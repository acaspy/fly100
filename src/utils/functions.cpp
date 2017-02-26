/*
 * functions.cpp
 *
 *  Created on: Feb 23, 2017
 *      Author: tsnappir
 */

#include "functions.h"

namespace DateUtils {

std::vector<std::vector<int> >  functions::spanDates(std::string s_start, std::string s_end, int flights, int diff) {
	my_date start = my_date(atoi(s_start.c_str()));
	my_date end = my_date(atoi(s_end.c_str()));
	int optionalDates = 2*diff+1;
	std::vector<std::vector<int> > res(flights+1,std::vector<int>(optionalDates));

	float step = (end-start) / (float) flights;
	int buf=0;
	for (int i=0; i<flights; i++) {
		res[i][0] = (int) start;
		for (int j=1; j<=diff; j++) {
			res[i][j] = start.getNextDate(j);
			res[i][optionalDates-j] = start.getPrevDate(j);
		}
		start + (int)(step*(i+1)-buf);
		buf = step*(i+1);
	}
	res[flights][0] = (int) end;
	for (int j=1; j<=diff; j++) {
		res[flights][j] = end.getNextDate(j);
		res[flights][optionalDates-j] = end.getPrevDate(j);
	}

	return res;
}

} /* namespace DateUtils */
