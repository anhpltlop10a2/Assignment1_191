/* Created by Nguyen Duc Dung on 2019-09-03.
 * =========================================================================================
 * Name        : processData.cpp
 * Author      : Duc Dung Nguyen
 * Email       : nddung@hcmut.edu.vn
 * Copyright   : Faculty of Computer Science and Engineering - HCMUT
 * Description : Implementation of main features in the assignment
 * Course      : Data Structure and Algorithms - Fall 2019
 * =========================================================================================
 */

#include "processData.h"

/* TODO: You can implement methods, functions that support your data structures here.
 * */
#include "dbLib.h"
using namespace std;

void Initialization() {
    // If you use global variables, please initialize them explicitly in this function.
}

void Finalization() {
    // Release your data before exiting
}

void ProcessRequest(const char* pRequest, void* pData, void* &pOutput, int &N) {
	// TODO: Implement this function for processing a request
	// NOTE: You can add other functions to support this main process.
	//       pData is a pointer to a data structure that manages the dataset
	//       pOutput is a pointer reference. It is set to nullptr and student must allocate data for it in order to save the required output
	//       N is the size of output, must be a non-negative number
	TDataset* myData = new TDataset();
	myData = (TDataset *)pData;

	string str1, str2, str3; 
	stringstream ss; 
	ss << pRequest; 
	ss >> str1 >> str2 >> str3 ; 
	//DEFINE COUNT OF FILE: 
	int count_cities, count_lines, count_station_lines, count_stations, count_tracks, count_track_lines = 0; 
	count_cities = myData->citiesList->getSize(); 
	count_lines = myData->linesList->getSize(); 
	count_station_lines = myData->station_lineList->getSize(); 
	count_stations = myData->stationList->getSize(); 
	count_tracks = myData->tracksList->getSize(); 
	count_track_lines = myData->track_lineList->getSize(); 
	//Request 1 ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	if (str1 == "CL" && str2 =="")
	{
		pOutput = new int*();
		*((int*)pOutput) = myData->get_SizeOFLine();
		N = 1;
	}
	//Request 2 ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	else if (str1 == "CL" && str2 != "")
	{
		string cityName = "";
		int count = 0;
		/////////////////////////////////////////
		if (str3 != "") cityName = str2 + " " +str3; 
		else cityName = str2; 
		/////////////////////////////////////////
		int saveID = 0; int isFind = 0;
		for (int i = 1; i <= count_cities ; i++)
		{
			if (cityName == myData->citiesList->at(i).name)
			{
				isFind = 1;
				saveID = myData->citiesList->at(i).id;
				break;
			}

		}
		if (isFind == 0) {
			isFind = -1;
		}
		pOutput = new int(isFind);
		if (isFind == 1) {

			for (int i = 1; i <= count_lines; i++)
			{
				if (saveID == myData->linesList->at(i).city_id)
				{
					count++;
				}
			}
			if (count != 0) {
				pOutput = new int(count);
				N = 1;
			}
			else {
				pOutput = new int(0);
				N = 1;
			}

		}
		
	}
	//Request 3 +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	else if (str1 == "LSC")
	{
		string cityName = ""; 
		///////////////////////////////////////
		if (str3 != "") cityName = str2 + " " + str3;
		else cityName = str2;
		/////////////////////////////////////////////
		int city_ID = 0;
		N = 0;
		int isfind = 0, count = 0;
		for (int i = 1; i <= count_cities; i++)
			if (cityName == myData->citiesList->at(i).name) 
			{
				isfind = 1;
				city_ID = myData->citiesList->at(i).id;
			}
		if (isfind == 0) {
			isfind = -1;
			pOutput = new int(isfind);
			N = 1;
		}
		if (isfind == 1)
		{
			for (int i = 1; i <= count_stations; i++)
				if (city_ID == myData->stationList->at(i).city_id)
				{
					count++;
				}
			pOutput = new int[count];
			for (int i = 1; i <= count_stations; i++) {
				if (city_ID == myData->stationList->at(i).city_id) {
					((int*)pOutput)[N++] = myData->stationList->at(i).id;
				}
			}
			if (count != 0) N = count;	
		}
	}
	//Request 4 +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	else if (str1 == "LLC")
	{
		string cityName = "";
		////////////////////////////////////////////////////
		if (str3 != "") cityName = str2 + " " + str3;
		else cityName = str2;
		///////////////////////////////////////////////////////
		int city_ID = 0;
		N = 0;
		int isfind = 0, count = 0;
		for (int i = 1; i <= count_cities; i++)
			if (cityName == myData->citiesList->at(i).name)
			{
				isfind = 1;
				city_ID = myData->citiesList->at(i).id;
			}
		if (isfind == 0) {
			isfind = -1;
			pOutput = new int(isfind);
			N = 1;
		}
		if (isfind == 1) 
		{
			int j = 0; 
			for (int i = 1; i <= count_lines; i++)
				if (city_ID == myData->linesList->at(i).city_id) count++;
			pOutput = new int[count];
			for (int i = 1; i <= count_lines; i++)
				if (city_ID == myData->linesList->at(i).city_id)
					((int*)pOutput)[N++] = myData->linesList->at(i).id;

			if (count != 0) N = count;	
		}
		
	}
	//Request 5 +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	else if (str1 == "LSL")
	{
		int line_ID = stoi(str2);
		int count = 0;
		bool isFound = false;
 		for (int i = 1; i <= count_station_lines; i++)
		{
			if (line_ID == myData->station_lineList->at(i).line_id){
				count++;
				isFound = true;
			}
		}
		if (isFound == true)
		{
			pOutput = new int[count]; N = count; 
			int j = 0;
			for (int i = 1; i <= count_station_lines; i++)
			{
				if (line_ID == myData->station_lineList->at(i).line_id)
				{
					((int*)pOutput)[j] = myData->station_lineList->at(i).station_id;
					j++;
				}
			}
		}
		else
		{
			pOutput = new int(-1);N = 1;
		}
	}
	//Request 6 ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	//Find a city with the given name. Return the first city_id if found, -1 otherwise.
	else if (str1 == "FC")
	{ 
	string cityName = ""; 
		////////////////////////////////////////
		if (str3 != "") cityName = str2 + " " + str3;
		else cityName = str2;
		////////////////////////////////////
		int city_ID = 0; 
		int isFound = 0;  
		for (int i = 1; i <= count_cities; i++){
			if (cityName == myData->citiesList->at(i).name)
			{
				isFound = 1;
				city_ID = myData->citiesList->at(i).id;
				break; 
			}
		}
		if (isFound == 0) pOutput = new int(-1); 
		if (isFound == 1) {
			pOutput = new int(city_ID);
		}
		N = 1;

	}
	//Request 7 ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	//Find a station with the given name. Return the first station_id if found, -1 otherwise.
	//Malpassé  id7719 
	else if (str1 == "FS")
	{
	//TEST : FS Rond-Point du Prado
	//test FS Palos de la Frontera
	//FS "Eugenia de Montijo"
	
	string stationName = "";
	string input = pRequest + 3;
	stringstream stst(input); 
	string tmp = "";
		
	if (stst.peek() == '"') {
		getline(stst, stationName, '"');
		getline(stst, stationName, '"');
		getline(stst, tmp, ',');
	}
	else  getline(stst, stationName, ',');
	///////////////////////////////////////////
	int station_id = 0;
	int isFound = 0;
		for (int i = 1; i <= count_stations; i++) {
			if (stationName == myData->stationList->at(i).name)
			{
				isFound = 1;
				station_id = myData->stationList->at(i).id;
				break; 
			}
		}
		if (isFound == 0) isFound = -1;
		pOutput = new int(isFound);
		if (isFound == 1) {
			pOutput = new int (station_id); 
		}
		N = 1;
	}
	//Request 8 +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	else if (str1 == "SLP")
	 {
	 //test : 8004 3826
		int index = 0;
		string geometryOfStation = ""; 
		string geometryOfTrack = ""; 
		int station_id = stoi(str2);
		int track_id = stoi(str3);
		int isFound = 0; 
		for (int i = 1; i <= count_stations; i++) {
			if (station_id == myData->stationList->at(i).id){
				isFound = 1;
				geometryOfStation = myData->stationList->at(i).geometry;
				geometryOfStation = geometryOfStation.substr(6, geometryOfStation.length() - 7);
				break;
			}
		}
		if (isFound == 0) {
			pOutput = new int(-1);N = 1;
			return; 
		}
		isFound = 0; 
		for (int i = 1; i <= count_tracks; i++) {
			if (track_id == myData->tracksList->at(i).id)
			{
				isFound = 1;
				geometryOfTrack = myData->tracksList->at(i).geometry;
				geometryOfTrack = geometryOfTrack.substr(11, geometryOfTrack.length() - 12);
				break;
			}
		}
		if (isFound == 0) {
			*(int*) pOutput = -1;
			N = 1;
			return;
		}
		//compare 
		string tmp = ""; 
		stringstream ss(geometryOfTrack); //cai linestring 
		getline(ss, tmp, ',');
		bool check = false;
		while (tmp != "")
		{
			if (tmp != geometryOfStation) //cai POINT
			{
				index++;
				if (!(getline(ss, tmp, ','))) break;
			}
			else {
				check = true; 
				break;
			}
		}
		if (check=false)
		{
			pOutput = new int(-1);
			N = 1;
		}
		else {
			pOutput = new int(index);
			N = 1;
		}	
	}
	
	//Request 9 +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++==================
	//Không break; 
	//IS Hoang Thuy Linh,POINT(-70.6087129 -33.42704),,1980,9999
	//IS "",POINT(123 562),15,5,64
	// IS Tuan anh,POINT(158 289566),5,6,9
	// IS Chuansha,POINT(121.693847 31.1842),2006,2010,9999
	else if (str1 == "IS") {
		int isFound = 0;
		string inSert = pRequest + 3; 
		stringstream stst(inSert);
		string tmp = "";
		TStation stationNode;
		int max = 0;

		for (int i = 1; i <= count_stations; i++) {

			if (myData->stationList->at(i).id > max) {
				max = myData->stationList->at(i).id;
			}
		}
		stationNode.id = max + 1;
		cout << stationNode.id; 
	if (stst.peek() == '"') {
		getline(stst, stationNode.name, '"');
		getline(stst, stationNode.name, '"');
		getline(stst, tmp, ',');
	}
	else getline(stst, stationNode.name, ','); 
	cout << stationNode.name<<endl; 

	getline(stst, tmp, ',');
	if (tmp != "") stationNode.geometry = tmp;
	
	cout << stationNode.geometry<<endl;  

	getline(stst, tmp, ',');
	if (tmp != "") stationNode.buildstart = stoi(tmp);
	else stationNode.buildstart = -1; 
	cout << stationNode.buildstart<<endl; 

	getline(stst, tmp, ',');
	if (tmp != "") {
		stationNode.opening = stoi(tmp);
		cout << stationNode.opening << endl;
	}
	else stationNode.opening = -1; 

	getline(stst, tmp);
	if (tmp != "") stationNode.closure = stoi(tmp);
	cout << stationNode.closure; 

	cout << endl;

	// insertLast 
	myData->stationList->push_back(stationNode);
	//cout << myData->stationList->at(15796).name; 
	pOutput = new int(max + 1);  
	N = 1; 
	}
	//Request 10  +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	//TEST: RS 7695 
	//TEST : RS 10666
	else if (str1 == "RS")
	{
	int isFound, result, index, city_ID = 0;
	int station_ID = stoi(str2);
	string geometryOfStation = "";
	string geometryOfTrack = "";
	for (int i = 1; i <= count_stations; i++) {

		//cout << myData->stationList->at(i).id <<endl; 
		if (station_ID == myData->stationList->at(i).id)
		{
			isFound = 1;
			result = myData->stationList->remove(i);
			//Tìm cityID de tra qua file TRack
			city_ID = myData->stationList->at(i).city_id; 
			geometryOfStation = myData->stationList->at(i).geometry;
			geometryOfStation = geometryOfStation.substr(6, geometryOfStation.length() - 7);
			break;
		}
	}
	//IF FOUND THEN XÓA NODE CÓ STATION_ID  TRONG FILE STATIONLINELIST
	if (isFound == 1)
	{
		for (int i = 1; i <= count_station_lines; i++)
		{
			if (station_ID == myData->station_lineList->at(i).station_id)
			{
				myData->station_lineList->remove(i);
				break;
			}
		}
		//Duyet tim LINESTRING tu city_ID trong file Track
		for (int i = 1; i <= count_tracks; i++)
		{
			if (city_ID == myData->station_lineList->at(i).city_id)
			{
				geometryOfTrack = myData->tracksList->at(i).geometry;
				geometryOfTrack = geometryOfTrack.substr(11, geometryOfTrack.length() - 12);
				index = i; 
				break;
			}
		}
		//compare 
		string tmp = "";
		stringstream ss(geometryOfTrack); //cai linestring 
		getline(ss, tmp, ',');
		bool check = false;
		while (tmp != "")
		{
			if (tmp != geometryOfTrack )//cai point
			{
				index++;
				if (!(getline(ss, tmp, ','))) break;
			}
			else {
				check = true;
				break;
			}
		}
		if (check = true) myData->tracksList->remove(index);
	}
	//IF FOUND THEN XÓA NODE CÓ GEOMETRY TRONG FILE 
	else if (isFound == 0) {
		result = -1;
	}
	pOutput = new int(result);
	N = 1;
	}
	//US 7509 Xuma,POINT(39.47511017 35.382846),129,199,999
	//TEst :: US 664 "Tuan anh",POINT(2.1 41.41),,0,195
	
	//CO COUT NHUNG CHUA XOA NHA TA CUTE MOT CHUT IT
	else if (pRequest[0] == 'U' && pRequest[1] == 'S')
	{
		int station_ID = stoi(str2);
		int len = str2.length();
		string upgrade = pRequest + len +4; 
		int index = 0; 
		int isfound = 0;
		TStation stationNode;

		for (int i = 1; i <= count_stations; i++) {

			if (station_ID == myData->stationList->at(i).id)
			{
				index = i;
				isfound = 1;
				break;
			}
		}
		if (isfound == 0) {
			pOutput = new int(-1);
			N = 1;
		}
		else if (isfound == 1) {
			pOutput = new int(0);
			N = 1;
		}
		stringstream stst(upgrade); 
		string tmp = ""; 
		//ugrade  US 7509 Hon-Ku,POINT(39.47511017 35.382846),129,199,999
		stationNode.id = station_ID; 

		if (stst.peek() == '"') {
			getline(stst, stationNode.name, '"');
			getline(stst, stationNode.name, '"');
			getline(stst, tmp, ',');
		}
		else getline(stst, stationNode.name, ',');
		myData->stationList->at(index).name = stationNode.name;

		cout << stationNode.name << endl;

		getline(stst, tmp, ',');
		if (tmp != "") stationNode.geometry = tmp;
		myData->stationList->at(index).geometry = stationNode.geometry;
		cout << stationNode.geometry << endl;

		getline(stst, tmp, ',');
		if (tmp != "") stationNode.buildstart = stoi(tmp); else stationNode.buildstart = -1;
		myData->stationList->at(index).buildstart = stationNode.buildstart;
		cout << stationNode.buildstart << endl;

		getline(stst, tmp, ',');
		if (tmp != "")  stationNode.opening = stoi(tmp);
		myData->stationList->at(index).opening = stationNode.opening;
		cout << stationNode.opening << endl;

		getline(stst, tmp);
		if (tmp != "") stationNode.closure = stoi(tmp);
		myData->stationList->at(index).closure = stationNode.closure;
		cout << stationNode.closure << endl; 
	}

	//Re11 +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ 
	else if (str1 == "ISL")
	{
	//TEST:  ISL 1604 571 2 
	int station_ID = stoi(str2);
	int line_ID = stoi(str3);
	int count1 = 0;  
	int len2 = str2.length(); 
	int len3 = str3.length(); 
	bool isFound = false; 
	int index = stoi(pRequest+len2+len3+6);
	int count = 0; 

	   // Duyet de lay phan tu cua mang arrIdx 
		for (int i = 1; i <= count_station_lines; i++)
		{
			if (line_ID == myData->station_lineList->at(i).line_id)
			{
				count++;
				if (station_ID == myData->station_lineList->at(i).station_id) {
					isFound = true;
					pOutput = new int(-1);
					N = 1;
					break;
				}
			}
		}
		
		
		//Neu khong tim thay thi insert: 
		if (isFound == false) 
		{
			pOutput = new int(0);
			N = 1;
			int *arrIdx = new int[count];
			int p_i = 0;
			for (int i = 0; i < count_station_lines; i++) {
				if (line_ID == myData->station_lineList->at(i+1).line_id) {
					arrIdx[p_i] = i + 1; 
					p_i++; 
				}
			}
			TStation_Line stationLineNode;
			stationLineNode.station_id = station_ID;
			stationLineNode.line_id = line_ID;
			stationLineNode.id = -1;
			stationLineNode.city_id = -1;
			stationLineNode.created_at = "";
			stationLineNode.updated_at = "";

			
			myData->station_lineList->insert(arrIdx[index]-1, stationLineNode);
		}
	}
	//Re13 +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++====++++++++++++++++++++++++++++++++++++++
	else if (str1 == "RSL") {
	// INPUT  RSL 7729 571 
	int station_ID = stoi(str2);
	int line_ID = stoi(str3);
	bool isFound = false;
	int result = 0;
	for (int i = 1; i <= count_station_lines; i++) {

		//cout << myData->station_lineList->at(i).station_id << endl; 
		//cout << myData->station_lineList->at(i).line_id << endl; 

		if (station_ID == myData->station_lineList->at(i).station_id && line_ID == myData->station_lineList->at(i).line_id)
		{
			isFound = true;
			result = myData->station_lineList->remove(i);
			break;
		}


	}
		if (isFound == false)
		{
			pOutput = new int(-1);
			N = 1; 
		}
		else
		{
			pOutput = new int(result);
			N = 1;
		}
	}
}


	
	



		


	

	


