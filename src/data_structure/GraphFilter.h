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
	//GraphFilter(Graph* g, std::vector<std::vector<int> >& dates);
	GraphFilter(Graph* g, std::vector<std::vector<int> >& dates, std::string requierdCities = "", std::string skipCities = "");
	virtual ~GraphFilter();
	virtual bool valid(Vertex* v);
	virtual bool valid(Edge* e) {return true;}
	std::vector<int> getDates ();
	virtual Vertex* getMainVertex(Vertex* v);

private:
	Graph* _g;
	bool _keepOtherCities;
    std::tr1::unordered_map<int,int> _dates;
    std::tr1::unordered_map<std::string,bool> _specCities;
};

} /* namespace dataStracture */

#endif /* DATA_STRUCTURE_GRAPHFILTER_H_ */
