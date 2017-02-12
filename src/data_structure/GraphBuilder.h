/*
 * GraphBuilder.h
 *
 *  Created on: Feb 10, 2017
 *      Author: tsnappir
 */

#ifndef DATA_STRUCTURE_GRAPHBUILDER_H_
#define DATA_STRUCTURE_GRAPHBUILDER_H_

#include "../file_parser/Csv.h"

namespace dataStracture {

class GraphBuilder {
public:
	GraphBuilder();
	virtual Graph* buildGraph(std::string file);
	virtual ~GraphBuilder();
};

} /* namespace dataStracture */

#endif /* DATA_STRUCTURE_GRAPHBUILDER_H_ */
