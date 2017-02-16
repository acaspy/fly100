/*
 * GraphFilter.h
 *
 *  Created on: Feb 12, 2017
 *      Author: tsnappir
 */

#ifndef DATA_STRUCTURE_GRAPHFILTER_H_
#define DATA_STRUCTURE_GRAPHFILTER_H_

#include "Graph.h"

namespace dataStracture {

class GraphFilter {
public:
	GraphFilter(std::vector<int>& dates) : _dates(dates) {}
	virtual ~GraphFilter();
	virtual bool valid(Vertex* v);
	std::vector<int> getDates () {return _dates;}
	void setFilteredCities(std::vector<std::string> cityNames) {
		_cities = cityNames;
	}

private:
	std::vector<int> _dates;
	std::vector<std::string> _cities;
};

} /* namespace dataStracture */

#endif /* DATA_STRUCTURE_GRAPHFILTER_H_ */
