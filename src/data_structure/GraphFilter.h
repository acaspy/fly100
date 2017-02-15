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
	GraphFilter();
	virtual ~GraphFilter();
	virtual bool valid(Vertex* v);
	void setDates(std::vector<int> dates) {
		_dates = dates;
	}
	void setFilteredCities(std::vector<std::string> cityNames) {
		_cities = cityNames;
	}

private:
	std::vector<int> _dates;
	std::vector<std::string> _cities;
};

} /* namespace dataStracture */

#endif /* DATA_STRUCTURE_GRAPHFILTER_H_ */
