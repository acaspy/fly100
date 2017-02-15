/*
 * dateUtils.h
 *
 *  Created on: Feb 13, 2017
 *      Author: tsnappir
 */

#ifndef UTILS_DATEUTILS_H_
#define UTILS_DATEUTILS_H_

#include <time.h>
#include <ctime>
#include <stdlib.h>
#include <vector>
#include <string>

namespace Utils {

class dateUtils {
public:
	dateUtils();
	virtual ~dateUtils();
	static void spanDates (std::vector<int>& dates, std::string start_s, std::string end_s, int flights);
};

} /* namespace Utils */

#endif /* UTILS_DATEUTILS_H_ */
