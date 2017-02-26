/*
 * GraphUtils.cpp
 *
 *  Created on: Feb 16, 2017
 *      Author: tsnappir
 */

#include "GraphUtils.h"

namespace Utils {

GraphUtils::GraphUtils() {
}

GraphUtils::~GraphUtils() {
}

void GraphUtils::addDummyEdges (dataStracture::Graph* g, const std::vector<int>& dates) {
	std::vector<std::tr1::unordered_map<std::string,geo::city*> > dummy (dates.size());
	std::vector<dataStracture::Vertex*> vertices = g->getVertices();
	for (unsigned int i=0;i<vertices.size(); i++) {
		geo::city* city = vertices[i]->getId();
		int flag=0;
		int d = city->getDate();
		unsigned int j;
		for (j=0; j<dates.size();j++) {
			if (d == dates[j]) {
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
				g->addEdge(it->second,dummy[i+1][it->first],new tran::transport(dummy[i][it->first],dummy[i+1][it->first],-1,-1));
			}
		}
	}
}


} /* namespace Utils */
