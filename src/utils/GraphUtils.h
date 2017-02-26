/*
 * GraphUtils.h
 *
 *  Created on: Feb 16, 2017
 *      Author: tsnappir
 */

#ifndef UTILS_GRAPHUTILS_H_
#define UTILS_GRAPHUTILS_H_

#include "../data_structure/Graph.h"

namespace Utils {

class GraphUtils {
public:
	GraphUtils();
	virtual ~GraphUtils();
	static void addDummyEdges(dataStracture::Graph* g, const std::vector<int>& dates);
};

} /* namespace Utils */

#endif /* UTILS_GRAPHUTILS_H_ */
