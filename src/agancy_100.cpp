//============================================================================
// Name        : agancy_100.cpp
// Author      : 
// Version     :
// Copyright   : Written by Tomer Snappir & Adir Caspy
// Description : Our new web low-cost transportation agency Server side
// API		   : API: (csv file of flights, start date, start city, end city, flights
//============================================================================

#include <iostream>
#include "data_structure/GraphBuilder.h"
#include "algo/salesMan.h"
#include "geo/city.h"
#include <time.h>
#include <ctime>
#include <stdlib.h>


using namespace std;


vector<int> spanDates (std::string start_s, std::string end_s, int flights) {
	int start = atoi(start_s.c_str());
	int end = atoi(end_s.c_str());

	int s_days = start % 100;
	int e_days = end % 100;
	start /= 100;
	end /= 100;
	int s_mons = start % 100;
	int e_mons = end % 100;
	start /= 100;
	end /= 100;

    struct std::tm s_date = {0,0,0,s_days,s_mons,start-1900};
    struct std::tm e_date = {0,0,0,e_days,e_mons,end-1900};

    std::time_t x = std::mktime(&s_date);
    std::time_t y = std::mktime(&e_date);



    double difference;
    if ( x != (std::time_t)(-1) && y != (std::time_t)(-1) ) {
        difference = std::difftime(y,x) / (60 * 60 * 24);
    } else {
    	vector<int> res;
    	return res;
    }
    double days4flight = difference / (flights-1);

    vector<int> res(flights);
    int buf = 0;;
    for (int i=0; i<flights-1; i++) {
    	s_date.tm_mday += days4flight*i-buf;
    	buf = days4flight*i;
    	res[i] = s_date.tm_mday + s_date.tm_mon*100 + (1900+s_date.tm_year)*10000;
    	//s_date.tm_mday += days4flight;
    }
    res[flights-1] = e_date.tm_mday + e_date.tm_mon*100 + (1900+e_date.tm_year)*10000;
	return res;
}


int main(int argc, char** argv) {
	//args needed (csv file of flights, start date, start city, end city, flights

	 if (argc != 7) {
		 std::cout << "Wrong usage. should be: (csv file of flights, start date, start city, end date, end city, flights)" << std::endl;
	 	 std::cout << "6 arguments are needed! got " << argc << ". exit..." << std::endl;
	 }
	std::string fn = argv[1];
	std::string start_date = argv[2];
	std::string start_city = argv[3];
	std::string end_date = argv[4];
	std::string end_city = argv[5];
	int flights = atoi(argv[6]);


/*
	std::string fn = "C:\\Users\\tsnappir\\new_eclipse\\flights.csv";
	std::string start_date = "20170401";
	std::string start_city = "WAW";
	std::string end_date = "20170420";
	std::string end_city = "WAW";
	std::string flights_s = "4";
	int flights = atoi(flights_s.c_str());
*/


	std::string start_algo = start_city + "_" + start_date;
	std::string end_algo = end_city + "_" + end_date;

	std::vector<int> dates = spanDates(start_date,end_date,flights);

	for (unsigned int i=0; i<4; i++) {
		std::cout << "flight on " << dates[i] << std::endl;
	}

	dataStracture::GraphBuilder gb;
	dataStracture::Graph* g = gb.buildGraph(fn);

	//std::cout << "Print g" << std::endl;
	//g->printGraph("C:\\Users\\tsnappir\\new_eclipse\\g2.csv");



	dataStracture::Graph* g3 = new dataStracture::Graph();
	g3->CloneFilteredGraph(g,dates,1,1);
	std::cout << "Print g3" << std::endl;
	g3->printGraph("C:\\Users\\tsnappir\\new_eclipse\\g3.csv");

	//std::cout << "Start to run algorithm" << std::endl;
	clock_t begin = clock();

	Graph_Algorithm::salesMan* sm = new Graph_Algorithm::salesMan(g3);
	clock_t end = clock();
	double elapsed_secs = double(end - begin) / (CLOCKS_PER_SEC/1000);

	sm->calc(flights*2-1,geo::city::getCity(start_algo),geo::city::getCity(end_algo));
	std::cout << "time meas: " << elapsed_secs ;
	return 0;
}
