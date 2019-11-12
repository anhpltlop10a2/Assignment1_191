/* Created by Nguyen Duc Dung on 2019-09-03.
 * =========================================================================================
 * Name        : dbLib.cpp
 * Author      : Duc Dung Nguyen
 * Email       : nddung@hcmut.edu.vn
 * Copyright   : Faculty of Computer Science and Engineering - HCMUT
 * Description : The data structure library for Assignment 1
 * Course      : Data Structure and Algorithms - Fall 2019
 * =========================================================================================
 */

#include "dbLib.h"

/* TODO: You can implement methods, functions that support your data structures here.
 * */


void LoadData(void* &pData) {


	pData = new void*; 

	//=================================================================================================================

	//define all bien 

	
	string id = "";
	string name = "";
	string coords = "";
	string start_year = "";
	string url_name = "";
	string country = "";
	string country_state = "";
	string  city_id = "";
	string color = "";
	string system_id = "";
	string transport_mode_id = "";
	string geometry = "";
	string buildstart="";
	string opening="";
	string closure="";
	string length="";
	string station_id = "";
	string line_id="";
	string created_at=""; 
	string updated_at = ""; 
	string section_id = ""; 

	//====================================================================================================================
	TDataset * Dataset = new TDataset;
	//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	//START TO READ cities.csv..........................................................
	ifstream fcities;
	fcities.open("cities.csv");
	TCity citycangetdata;
	getline(fcities, id);
	while (!fcities.eof()) {
		getline(fcities, id, ',');
		if (id == "") break; 
		else citycangetdata.id = atoi(id.c_str());

		//cout << citycangetdata.id <<", " ;

		getline(fcities, name, ',');
		citycangetdata.name = name;
		//cout << citycangetdata.name<<", " ;

		getline(fcities, coords, ',');
		citycangetdata.coords = coords;
		//cout << citycangetdata.coords << ", ";

		getline(fcities, start_year, ',');
		citycangetdata.start_year = atoi(start_year.c_str());
		//cout << citycangetdata.start_year << ", ";

		getline(fcities, url_name, ',');
		citycangetdata.url_name = url_name;
		//cout << citycangetdata.url_name << ", ";

		getline(fcities, country, ',');
		citycangetdata.country = country;
		//cout << citycangetdata.country << ", ";

		getline(fcities, country_state);
		citycangetdata.country_state = country_state;
		//cout << citycangetdata.country_state << endl; 
	
		

		Dataset->get_cities(citycangetdata);

	}
	fcities.close();
	//cout << Dataset->citiesList->getSize()<<"City"<<endl; 
	
	

	//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	//START TO READ station.csv......................................................................
	ifstream fstation;
	TStation Stationcangetdata;
	string readAStation = ""; 
	fstation.open("stations.csv");
	getline(fstation, id);
	while (getline(fstation, readAStation))
	{
		//id, string name, string geometry, buildstart, opening, closure, city_id
		stringstream stst(readAStation);
		getline(stst, id, ',');
		if (id != "") Stationcangetdata.id = atoi(id.c_str());
		//cout << Stationcangetdata.id << ", "<<endl;


		if (stst.peek() == '"') {
			getline(stst, Stationcangetdata.name, '"');
			getline(stst, Stationcangetdata.name, '"');
			getline(stst, name, ',');
		}
		else  getline(stst, Stationcangetdata.name, ',');

		//cout << Stationcangetdata.name << endl;

		getline(stst, geometry, ',');
		if (geometry != "") Stationcangetdata.geometry = geometry;
		//cout << Stationcangetdata.geometry << ", ";

		getline(stst, buildstart, ',');
		if (buildstart != "") Stationcangetdata.buildstart = atoi(buildstart.c_str());
		//cout << Stationcangetdata.buildstart<<", ";

		getline(stst, opening, ',');
		if (opening != "") Stationcangetdata.opening = atoi(opening.c_str());
		//cout << Stationcangetdata.opening << ", ";

		getline(stst, closure, ',');
		if (closure != "") Stationcangetdata.closure = atoi(closure.c_str());
		//cout << Stationcangetdata.closure << ", ";

		getline(stst, city_id);
		if (city_id != "")Stationcangetdata.city_id = atoi(city_id.c_str());
		//cout << Stationcangetdata.city_id << endl;




		////////////////////////////////////////////////////////
		Dataset->get_stationList(Stationcangetdata);
	}
	fstation.close();
	//cout << Dataset->stationList->getSize() <<"station"<<endl;

	
	//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	
	// IMPLIMENT READ STATIONLINESLIST
	//START TO READ station_lines.csv......................................................................
	ifstream fstation_lines;
	TStation_Line Station_linesCangetdata;
	fstation_lines.open("station_lines.csv");
	getline(fstation_lines, id);
	while (!fstation_lines.eof())
	{
		// int id;int station_id;int line_id;int city_id;string created_at;string updated_at;//
		getline(fstation_lines, id, ',');
		if (id != "") Station_linesCangetdata.id = atoi(id.c_str());
		else break; 

		//cout << Station_linesCangetdata.id << ", ";

		getline(fstation_lines, station_id, ',');
		if (station_id != "") Station_linesCangetdata.station_id = atoi(station_id.c_str());
		//cout << Station_linesCangetdata.station_id << ", ";

		getline(fstation_lines, line_id, ',');
		if (line_id != "") Station_linesCangetdata.line_id = atoi(line_id.c_str());
		//cout << Station_linesCangetdata.line_id << ", ";

		getline(fstation_lines, city_id, ',');
		if (city_id != "") Station_linesCangetdata.city_id = atoi(city_id.c_str());
		//cout << Station_linesCangetdata.city_id << ", ";

		getline(fstation_lines, created_at, ',');
		if (created_at != "") Station_linesCangetdata.created_at = created_at;
		//cout << Station_linesCangetdata.created_at << ", ";

		getline(fstation_lines, updated_at);
		if (updated_at != "") Station_linesCangetdata.updated_at = updated_at;
		//cout << Station_linesCangetdata.updated_at << endl;
		////////////////////////////////////////////////////////
		Dataset->get_station_linesList(Station_linesCangetdata);
	}
	fstation_lines.close();
	//cout << Dataset->station_lineList->getSize()<<"stationLine"<<endl; 

	
	//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	//START TO READ tracks.csv......................................................................
	ifstream ftracks;
	TTrack Trackcangetdata;
	ftracks.open("tracks.csv");
	getline(ftracks, id);
	while (!ftracks.eof())
	{
		//int id;string geometry;int buildstart;int opening;int closure;int length;int city_id;
		getline(ftracks, id, ',');
		if (id != "") Trackcangetdata.id = atoi(id.c_str());
		//cout << Trackcangetdata.id << ", ";

		getline(ftracks, geometry, '"');
		getline(ftracks, geometry, '"');
		if (geometry != "") Trackcangetdata.geometry = geometry;
		//cout << Trackcangetdata.geometry << endl;

		getline(ftracks, buildstart, ',');
		getline(ftracks, buildstart, ',');
		if (buildstart != "") Trackcangetdata.buildstart = atoi(buildstart.c_str());
		//cout << Trackcangetdata.buildstart << ", "; 

		getline(ftracks, opening, ',');
		if (opening != "") Trackcangetdata.opening = atoi(opening.c_str());
		//cout << Trackcangetdata.opening << ", ";


		getline(ftracks, closure, ',');
		if (closure != "") Trackcangetdata.closure = atoi(closure.c_str());
		//cout << Trackcangetdata.closure << ", "; 

		getline(ftracks, length, ',');
		if (length != "") Trackcangetdata.length = atoi(length.c_str());
		//cout << Trackcangetdata.length << ", ";

		getline(ftracks, city_id);
		if (city_id != "") Trackcangetdata.city_id = atoi(city_id.c_str());
		//cout << Trackcangetdata.city_id << endl;

		////////////////////////////////////////////////////////
		Dataset->get_tracks(Trackcangetdata);
	}
	ftracks.close();
	//cout << Dataset->tracksList->getSize()<<"track"<<endl; 

	//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++=
	//Start to read track_lines.csv 
	ifstream ftrack_lines;
	TTrack_Line Track_linesCangetdata;
	ftrack_lines.open("track_lines.csv");
	getline(ftrack_lines, id);
	while (!ftrack_lines.eof())
	{
		// id, section_id, line_id, string created_at, string updated_at,  city_id
		getline(ftrack_lines, id, ',');
		if (id != "") Track_linesCangetdata.id = atoi(id.c_str());
		else break; 
		//cout << Track_linesCangetdata.id << ", ";

		getline(ftrack_lines, section_id, ',');
		if (section_id != "") Track_linesCangetdata.section_id = atoi(section_id.c_str());
		//cout << Track_linesCangetdata.section_id << ", ";

		getline(ftrack_lines, line_id, ',');
		if (line_id != "") Track_linesCangetdata.line_id = atoi(line_id.c_str());
		//cout << Track_linesCangetdata.line_id << ", ";

		getline(ftrack_lines, created_at, ',');
		if (created_at != "") Track_linesCangetdata.created_at = created_at;
		//cout << Track_linesCangetdata.created_at << ", ";


		getline(ftrack_lines, updated_at, ',');
		if (updated_at != "") Track_linesCangetdata.updated_at = updated_at;
		//cout << Track_linesCangetdata.updated_at << ", ";

		getline(ftrack_lines, city_id);
		if (city_id != "") Track_linesCangetdata.city_id = atoi(city_id.c_str());
		//cout << Track_linesCangetdata.city_id << endl;

		
		////////////////////////////////////////////////////////
		Dataset->get_tracks_lineList(Track_linesCangetdata);
	}
	ftracks.close();
	//cout << Dataset->track_lineList->getSize()<<"trackline"<<endl; 

	//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++=
	//Start to read lines.csv
	ifstream flines;
	TLine lineCangetData;
	string readALine = ""; 
	flines.open("lines.csv");
	getline(flines, id);
	while (getline(flines,readALine))
	{
		// id;  city_id;string name;string url_name;string color;system_id; transport_mode_id;
		stringstream ss(readALine); 
		getline(ss, id, ',');
		if (id != "") lineCangetData.id = atoi(id.c_str());
		//cout << lineCangetData.id << ", ";

		getline(ss, city_id, ',');
		if (city_id != "") lineCangetData.city_id = atoi(city_id.c_str());
		//cout << lineCangetData.city_id<< ", ";

		

		if (ss.peek() == '"') {
			getline(ss, lineCangetData.name, '"');
			getline(ss, lineCangetData.name, '"');
			getline(ss, name, ',');
		}
		else  getline(ss, lineCangetData.name, ',');
		//cout << lineCangetData.name << ", ";

		getline(ss, url_name, ',');
		if (url_name != "") lineCangetData.url_name = url_name;
		//cout << lineCangetData.url_name << ", ";

		getline(ss, color, ',');
		if (color  != "") lineCangetData.color = color;
		//cout << lineCangetData.color << ", ";


		getline(ss, system_id, ',');
		if (system_id != "") lineCangetData.system_id = atoi(system_id.c_str());
		//cout << lineCangetData.system_id << ", ";

		getline(ss, transport_mode_id);
		if (transport_mode_id != "") lineCangetData.transport_mode_id = atoi(transport_mode_id.c_str());
		//cout << lineCangetData.transport_mode_id << endl;


		////////////////////////////////////////////////////////
		Dataset->get_lines(lineCangetData);
	}
	flines.close();
	//cout << Dataset->linesList->getSize()<<"line"<<endl; 


	//////////////////////////////////////////////////////////////////////////////////////////////
	pData = new TDataset*();
	pData = Dataset;
	Dataset = nullptr;
	delete Dataset;



}
	
void ReleaseData(void* &pData) {
	pData = nullptr;
}