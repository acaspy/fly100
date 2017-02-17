/*
 * GraphFilter.cpp
 *
 *  Created on: Feb 12, 2017
 *      Author: tsnappir
 */

#include "GraphFilter.h"

namespace dataStracture {


GraphFilter::~GraphFilter() {
}

bool GraphFilter::valid(Vertex* v) {
	bool flag = false;
	for (unsigned int i=0; i< _dates.size(); i++) {
		if (_dates[i] == v->getId()->getDate()) {
			flag = true;
		}
	}
	if (! flag) {
		return false;
	}
	for (unsigned int i=0; i< _cities.size(); i++) {
		if (_cities[i] == v->getId()->getName()) {
			return false;
		}
	}
	return true;
}


} /* namespace dataStracture */
