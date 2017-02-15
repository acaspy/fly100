/*
 * addDummyEdges.h
 *
 *  Created on: Feb 13, 2017
 *      Author: tsnappir
 */

#ifndef DATA_STRUCTURE_ADDDUMMYEDGES_H_
#define DATA_STRUCTURE_ADDDUMMYEDGES_H_

#include "GraphManipulator.h"

namespace dataStracture {

class addDummyEdges: public GraphManipulator {
public:
	addDummyEdges(Graph* g, std::vector<int>& dates) : _dates(dates), _g(g) {}
	virtual ~addDummyEdges();
	virtual void manipulate();
private:
	std::vector<int> _dates;
	Graph* _g;
};

} /* namespace dataStracture */

#endif /* DATA_STRUCTURE_ADDDUMMYEDGES_H_ */
