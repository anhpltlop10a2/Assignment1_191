#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstring>
#include <sstream>
#include <math.h>

#include "dsaLib.h"
#include "dbLib.h"
#include "processData.h"

using namespace std;

int main() {
    Initialization();

    void*   pData = nullptr;
    void*   pOutput = nullptr;
    int     N;
	//TO COUNT TIME
	clock_t a, b; //
	a = clock(); //
	

    LoadData(pData);
	b = clock(); //
	cout << "Times:" << (double)(b - a) / CLOCKS_PER_SEC << endl;//
	//cout << endl;// 
    assert(pData != nullptr);
    cout << fixed << setprecision(8);
    string req;
    while (true) {
        req = "";
        getline(cin, req);
        if (cin.bad()) {
            cin.clear();
            cin.ignore(1024, '\n');
            continue;
        }
        if (req == "Exit") {
            break;
        }
		clock_t c, d;// 
		c = clock(); //
		ProcessRequest(req.data(), pData, pOutput, N);
		d = clock(); //
		cout << "Times:" << double(d - c) / CLOCKS_PER_SEC << endl; //
        PrintReqOutput<int>(req.data(), (int*)pOutput, N);
		cout << endl; //
        delete [] (int*)pOutput;
        pOutput = nullptr;
    }

    ReleaseData(pData);
    Finalization();
    return 0;
}