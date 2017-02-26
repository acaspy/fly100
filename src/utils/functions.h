/*
 * functions.h
 *
 *  Created on: Feb 23, 2017
 *      Author: tsnappir
 */

#ifndef UTILS_FUNCTIONS_H_
#define UTILS_FUNCTIONS_H_

#include <string>
#include <vector>
#include <stdlib.h>
#include "my_date.h"


namespace DateUtils {

class functions {
public:
	functions();
	virtual ~functions();
	static std::vector<std::vector<int> >  spanDates(std::string s_start, std::string s_end, int flights, int diff);
};

} /* namespace DateUtils */

#endif /* UTILS_FUNCTIONS_H_ */
