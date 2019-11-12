/* Created by Nguyen Duc Dung on 2019-09-03.
 * =========================================================================================
 * Name        : dbLib.h
 * Author      : Duc Dung Nguyen
 * Email       : nddung@hcmut.edu.vn
 * Copyright   : Faculty of Computer Science and Engineering - HCMUT
 * Description : The data structure library for Assignment 1
 * Course      : Data Structure and Algorithms - Fall 2019
 * =========================================================================================
 */

#ifndef DSA191_A1_DBLIB_H
#define DSA191_A1_DBLIB_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstring>
#include <sstream>
#include <math.h>

#include "dsaLib.h"

/* TODO: Please design your data structure carefully so that you can work with the given dataset
 *       in this assignment. The below structures are just some suggestions.
 */
struct TCity {
    // The structure to store city information
	int id;
	string name;
	string coords;
	int start_year;
	string url_name;
	string country;
	string country_state;
};

struct TLine {
    // The structure to store line information
	int id;
	int  city_id;
	string name;
	string url_name;
	string color;
	int system_id;
	int transport_mode_id;
};

struct TTrack {
    // The structure to store track information
	int id;
	string geometry;
	int buildstart;
	int opening;
	int closure;
	int length;
	int city_id;
};
struct TStation{

	int id;
	string name;
	string geometry;
	int buildstart;
	int opening;
	int closure;
	int city_id;
};
struct TStation_Line {


	int id;
	int station_id;
	int line_id;
	int city_id;
	string created_at;
	string updated_at;
	
};
struct TTrack_Line {

	int id;
	int section_id;
	int line_id;
	string created_at;
	string updated_at;
	int city_id;
};
class TDataset {
    // This class can be a container that help you manage your tables
public:

	L1List<TCity> *citiesList = new L1List<TCity>;
	L1List<TLine> *linesList = new L1List<TLine>;
	L1List<TTrack> *tracksList = new L1List<TTrack>;
	L1List<TStation> *stationList = new L1List<TStation>;
	L1List<TTrack_Line> *track_lineList= new L1List<TTrack_Line>;
	L1List<TStation_Line> *station_lineList = new L1List<TStation_Line>;

public:
	void get_cities(TCity &data) {
		citiesList->push_back(data);
	}
	void get_lines(TLine &data) {
		linesList->push_back(data);
	}
	void get_tracks(TTrack &data) {
		tracksList->push_back(data);
	}
	void get_stationList(TStation &data) {
		stationList->push_back(data);
	}
	void get_tracks_lineList(TTrack_Line &data) {
		track_lineList->push_back(data);
	}
	void get_station_linesList(TStation_Line &data) {
		station_lineList->push_back(data);
	}
	int get_SizeOFLine() {
		return linesList->getSize(); 
	}

	
};

// Please add more or modify as needed

void LoadData(void* &);
void ReleaseData(void* &);

#endif //DSA191_A1_DBLIB_H
