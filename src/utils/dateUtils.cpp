/*
 * dateUtils.cpp
 *
 *  Created on: Feb 13, 2017
 *      Author: tsnappir
 */

#include "dateUtils.h"

namespace Utils {

dateUtils::dateUtils() {
}

dateUtils::~dateUtils() {
}

void dateUtils::spanDates (std::vector<int>& dates, std::string start_s, std::string end_s, int flights) {
	int start = atoi(start_s.c_str());
	int end = atoi(end_s.c_str());

	int s_days = start % 100;
	int e_days = end % 100;
	start /= 100;
	end /= 100;
	int s_mons = start % 100;
	int e_mons = end % 100;
	start /= 100;
	end /= 100;

    struct std::tm s_date = {0,0,0,s_days,s_mons,start-1900};
    struct std::tm e_date = {0,0,0,e_days,e_mons,end-1900};

    std::time_t x = std::mktime(&s_date);
    std::time_t y = std::mktime(&e_date);



    double difference;
    if ( x != (std::time_t)(-1) && y != (std::time_t)(-1) ) {
        difference = std::difftime(y,x) / (60 * 60 * 24);
    } else {
    	return;
    }
    double days4flight = difference / (flights-1);

    int buf = 0;;
    for (int i=0; i<flights-1; i++) {
    	s_date.tm_mday += days4flight*i-buf;
    	buf = days4flight*i;
    	dates[i] = s_date.tm_mday + s_date.tm_mon*100 + (1900+s_date.tm_year)*10000;
    	//s_date.tm_mday += days4flight;
    }
    dates[flights-1] = e_date.tm_mday + e_date.tm_mon*100 + (1900+e_date.tm_year)*10000;
	return;
}

} /* namespace Utils */
