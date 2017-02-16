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
#include "data_structure/GraphFilter.h"

#include "algo/salesMan.h"
#include "utils/dateUtils.h"
#include "utils/GraphUtils.h"
#include "geo/city.h"
#include <time.h>
#include <ctime>
#include <stdlib.h>


using namespace std;

int main(int argc, char** argv) {
	//args needed (csv file of flights, start date, start city, end city, flights

	 if (argc != 7) {
		 std::cout << "Wrong usage. should be: (csv file of flights, start date, start city, end date, end city, flights)" << std::endl;
	 	 std::cout << "6 arguments are needed! got " << argc << std::endl;
	 	 std::cout << "usage example: agency_100.exe C:\\Users\\tsnappir\\new_eclipse\\flights.csv 20170401 WAW 20170420 WAW 4" << std::endl << "exit...";
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

	std::vector<int> dates (flights);
	Utils::dateUtils::spanDates(dates,start_date,end_date,flights);

	for (unsigned int i=0; i<dates.size(); i++) {
		std::cout << "flight on " << dates[i] << std::endl;
	}

	dataStracture::GraphBuilder gb;
	dataStracture::Graph* g = gb.buildGraph(fn);

	//std::cout << "Print g" << std::endl;
	//g->printGraph("C:\\Users\\tsnappir\\new_eclipse\\g2.csv");

	dataStracture::GraphFilter* gf = new dataStracture::GraphFilter(dates);
	dataStracture::Graph* g3 = gb.buildGraph(g,gf,1);

	//std::cout << "Print g3 before man" << std::endl;
	//g3->printGraph("C:\\Users\\tsnappir\\new_eclipse\\g3.csv");

	//g3->printGraph("C:\\Users\\tsnappir\\new_eclipse\\g4.csv");
	//std::cout << "Start to run algorithm" << std::endl;
	clock_t begin = clock();

	Graph_Algorithm::salesMan* sm = new Graph_Algorithm::salesMan(g3);
	clock_t end = clock();
	double elapsed_secs = double(end - begin) / (CLOCKS_PER_SEC/1000);
	sm->calc(flights*2-1,geo::city::getCity(start_algo),geo::city::getCity(end_algo));
	std::cout << "time meas: " << elapsed_secs ;

	return 0;
}
