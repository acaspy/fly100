/*
 * GraphBuilder.cpp
 *
 *  Created on: Feb 10, 2017
 *      Author: tsnappir
 */

#include "GraphBuilder.h"

namespace dataStracture {

GraphBuilder::GraphBuilder() {}

GraphBuilder::~GraphBuilder() {}


Graph* GraphBuilder::buildGraph(std::string file) {
	Graph* g = new Graph();
	parser::Csv* p = new parser::Csv(file);
	std::cout << "Starting to parse " << file << std::endl;
	p->parse(g);
	delete p;
	return g;
}

}/* namespace dataStracture */
