/*
 * addDummyEdges.cpp
 *
 *  Created on: Feb 13, 2017
 *      Author: tsnappir
 */

#include "addDummyEdges.h"

namespace dataStracture {

addDummyEdges::~addDummyEdges() {
}

void addDummyEdges::manipulate() {
	std::vector<std::tr1::unordered_map<std::string,geo::city*> > dummy (_dates.size());
	std::vector<Vertex*> vertices = _g->getVertices();
	for (unsigned int i=0;i<vertices.size(); i++) {
		geo::city* city = vertices[i]->getId();
		int flag=0;
		int d = city->getDate();
		unsigned int j;
		for (j=0; j<_dates.size();j++) {
			if (d == _dates[j]) {
				flag=1;
				break;
			}
		}
		if (flag) {
			dummy[j][city->getName()] = city;
		}
	}

	for (unsigned int i=0;i<dummy.size()-1;i++) {
		for (std::tr1::unordered_map<std::string,geo::city*>::iterator it=dummy[i].begin();it!=dummy[i].end();it++) {
			if (dummy[i+1].count(it->first) != 0) {
				_g->addEdge(it->second,dummy[i+1][it->first],new tran::transport(dummy[i][it->first],dummy[i+1][it->first],-1));
			}
		}
	}

}

} /* namespace dataStracture */
