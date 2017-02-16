/*
 * GraphBuilder.cpp
 *
 *  Created on: Feb 10, 2017
 *      Author: tsnappir
 */

#include "GraphBuilder.h"
#include "../utils/GraphUtils.h"

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

//Graph* GraphBuilder::buildGraph(Graph* g,vector<int>, int addEdges, int addDummyEdges) {

Graph* GraphBuilder::buildGraph(Graph* g, GraphFilter* gf, int addEdges, int addDummyEdges) {
	Graph* ng = new Graph();
	std::vector<Vertex*> origVertices = g->getVertices();
	std::vector<Vertex*> afterFilterVertices;
	for (unsigned int i=0;i<origVertices.size(); i++) {
		Vertex* v = origVertices[i];

		if (gf) {
			if (! gf->valid(v)) {
				continue;
			}
		}
		afterFilterVertices.push_back(v);
		ng->addVertex(v->getId());
	}
	if (! addEdges) {
		return ng;
	}
	for (unsigned int i=0;i<afterFilterVertices.size();i++) {
		Vertex* v = afterFilterVertices[i];
		std::vector<Edge*> edges = v->getEdges();
		for (unsigned j=0; j<edges.size();j++) {
			geo::city* dest = edges[j]->getDestination()->getId();
			Vertex* to = ng->getVertex(dest);
			if (to) {
				ng->addEdge(v->getId(),dest,edges[j]->getTran());
			}
		}
	}
	return ng;
}




}/* namespace dataStracture */
