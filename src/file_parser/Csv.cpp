/*
 * Csv.cpp
 *
 *  Created on: Jan 24, 2017
 *      Author: tsnappir
 */

#include "Csv.h"

namespace parser {


Csv::~Csv() {
}

void Csv::parse(dataStracture::Graph* g) {
	//std::tr1::unordered_map<std::string,geo::city*> places;
	int line_length = 8;
	std::ifstream input( _file.c_str() );
	std::vector<std::string> arr_string(line_length);
	std::string from;
	std::string to;
	geo::city* city_from;
	geo::city* city_to;
	tran::transport* t;
	dataStracture::Edge* e;
	for( std::string line; getline( input, line ); ) {
		std::istringstream ss(line);
		std::string token;
		for (int i=0;i<line_length;i++) {
			std::getline(ss, token, ',');
			arr_string[i] = token;
			//std::cout << token << " ";
		}
		from = arr_string[0] + "_" + arr_string[2];
		to = arr_string[1] + "_" + arr_string[2];
		double cost = atof( arr_string[5].c_str());
		int date = atoi( arr_string[2].c_str());
		city_from = geo::city::getCity(from);
		dataStracture::Vertex* v_from = g->getVertex(city_from);
		if (v_from == 0) {
			city_from = new geo::cityday(arr_string[0],date);
			v_from = g->CreateVertex(city_from);
		}
		city_to = geo::city::getCity(to);
		dataStracture::Vertex* v_to  = g->getVertex(city_to);
		if (v_to == 0) {
			city_to = new geo::cityday(arr_string[1],date);
			v_to = g->CreateVertex(city_to);
		}
		e = v_from->getEdge(v_to);
		if (e != 0) {
			t = e->getTran();
			if (cost < t->getCost()) {
				t = new tran::transport(city_from,city_to,cost,date);
				g->updateEdge(city_from,city_to,t);
			}
		} else {
			t = new tran::transport(city_from,city_to,cost,date);
			// if exist - take the cheapest flight
			g->addEdge(city_from,city_to,t);
		}
	}
}


} /* namespace parser */
