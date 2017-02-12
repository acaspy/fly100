/*
 * cityday.h
 *
 *  Created on: Jan 19, 2017
 *      Author: tsnappir
 */

#ifndef GEO_CITYDAY_H_
#define GEO_CITYDAY_H_

#include "city.h"

namespace geo {

class cityday: public geo::city {
public:
	cityday(std::string id, int date);
	virtual ~cityday();

private:
};

}
#endif /* GEO_CITYDAY_H_ */
