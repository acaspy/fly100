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
#include "utils/functions.h"
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
	//int flex = atoi(argv[7]);
	//int uniqe_city = atoi(argv[8]);


	std::string debug_graph1 = "";
	std::string debug_graph2 = "";
	bool debug = false;
	if (argc >7) {
		debug_graph1 = argv[7];
		debug_graph2 = argv[8];
		debug = true;
	}

	std::string start_algo = start_city + "_" + start_date;
	std::string end_algo = end_city + "_" + end_date;

	std::vector<std::vector<int> > dates =	DateUtils::functions::spanDates(start_date,end_date,flights-1,1);

	if (debug) {
		for (unsigned int i=0; i< dates.size();i++) {
			std::cout << i << std::endl;
			for (unsigned int j=0; j< dates[i].size();j++) {
				std::cout << dates[i][j] << " , ";
			}
			std::cout << std::endl;
		}
	}

	dataStracture::GraphBuilder gb;
	dataStracture::Graph* g = gb.buildGraph(fn);

	if (debug) {
		std::cout << "Print g" << std::endl;
		if (debug_graph1 != "") {
			g->printGraph();
		} else {
			std::ofstream fd(debug_graph1.c_str());
			g->printGraph(fd);
		}

		std::cout << "Done" << std::endl;
	}

	dataStracture::GraphFilter* gf = new dataStracture::GraphFilter(g,dates);
	dataStracture::Graph* g3 = gb.buildGraph(g,gf,1);

	if (debug) {
		std::cout << "Print final graph before algorithm" << std::endl;
		if (debug_graph2 != "") {
			g3->printGraph();
		} else {
			std::ofstream fd(debug_graph2.c_str());
			g3->printGraph(fd);
		}
		std::cout << "Done" << std::endl;
	}

	std::cout << "Start to run algorithm" << std::endl;
	clock_t begin = clock();

	Graph_Algorithm::salesMan* sm = new Graph_Algorithm::salesMan(g3,gf);
	clock_t end = clock();
	double elapsed_secs = double(end - begin) / (CLOCKS_PER_SEC/1000);
	sm->calc(flights*2-1,geo::city::getCity(start_algo),geo::city::getCity(end_algo));
	std::cout << "time meas: " << elapsed_secs ;

	return 0;
}
