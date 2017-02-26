/*
 * GraphFilter.h
 *
 *  Created on: Feb 12, 2017
 *      Author: tsnappir
 */

#ifndef DATA_STRUCTURE_GRAPHFILTER_H_
#define DATA_STRUCTURE_GRAPHFILTER_H_

#include "Graph.h"
#include <iostream>
#include <string>

namespace dataStracture {

class GraphFilter {
public:
	GraphFilter(Graph* g, std::vector<std::vector<int> >& dates);
	virtual ~GraphFilter();
	virtual bool valid(Vertex* v);
	virtual bool valid(Edge* e) {return true;}
	std::vector<int> getDates ();
	void setFilteredCities(std::vector<std::string> cityNames) {
		_cities = cityNames;
	}
	virtual Vertex* getMainVertex(Vertex* v);

private:
	Graph* _g;
    std::tr1::unordered_map<int,int> _dates;
	std::vector<std::string> _cities;
};

} /* namespace dataStracture */

#endif /* DATA_STRUCTURE_GRAPHFILTER_H_ */
