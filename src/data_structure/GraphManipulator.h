/*
 * GraphManipulator.h
 *
 *  Created on: Feb 13, 2017
 *      Author: tsnappir
 */

#ifndef DATA_STRUCTURE_GRAPHMANIPULATOR_H_
#define DATA_STRUCTURE_GRAPHMANIPULATOR_H_

#include "Graph.h"

namespace dataStracture {

class GraphManipulator {
public:
	GraphManipulator() {}
	virtual ~GraphManipulator();
	virtual void manipulate() = 0;
};

} /* namespace dataStracture */

#endif /* DATA_STRUCTURE_GRAPHMANIPULATOR_H_ */
