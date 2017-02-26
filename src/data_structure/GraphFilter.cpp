/*
 * GraphFilter.cpp
 *
 *  Created on: Feb 12, 2017
 *      Author: tsnappir
 */

#include "GraphFilter.h"

namespace dataStracture {


GraphFilter::GraphFilter(Graph* g, std::vector<std::vector<int> >& dates) : _g(g) {
	for (int i=0; i<dates.size();i++) {
		for (int j=0; j<dates[i].size();j++) {
			_dates[dates[i][j]] = dates[i][0];
		}
	}
}

GraphFilter::~GraphFilter() {
}

bool GraphFilter::valid(Vertex* v) {
	if (_dates.count(v->getId()->getDate()) == 0) {
		return false;
	}

	for (unsigned int i=0; i< _cities.size(); i++) {
		if (_cities[i] == v->getId()->getName()) {
			return false;
		}
	}
	return true;
}


Vertex* GraphFilter::getMainVertex(Vertex* v) {
	Vertex* ret = _g->getVertex(geo::city::getCity(v->getId()->getName()+ "_" + static_cast<std::ostringstream*>( &(std::ostringstream() << _dates[v->getId()->getDate()]) )->str()));
	if (ret==0) {
		ret = _g->CreateVertex(new geo::city(v->getId()->getName(),_dates[v->getId()->getDate()]));
	}
	return ret;
}

std::vector<int> GraphFilter::getDates () {
	std::map<int,int> hash;
	for (std::tr1::unordered_map<int,int>::iterator it = _dates.begin(); it!= _dates.end();it++) {
		hash[it->second] = 1;
	}
	std::vector<int> res;
	for (std::map<int,int>::iterator it = hash.begin(); it != hash.end(); it++) {
		res.push_back(it->first);
	}
	return res;
}

} /* namespace dataStracture */
