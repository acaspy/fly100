/*
 * my_date.h
 *
 *  Created on: Feb 22, 2017
 *      Author: tsnappir
 */

#ifndef UTILS_my_date_H_
#define UTILS_my_date_H_

namespace DateUtils {

class my_date {
public:
	my_date(int my_date);
	virtual ~my_date();

	int operator-(my_date& d1);
	void operator+(int days);

	operator int() const { return _day + 100*_month+10000*_year; }
	int getDay() {return _day;}
	int getMonth() {return _month;}
	int getYear() {return _year;}
	int getNextDate(int days);
	int getPrevDate(int days);
private:
	static  int _month_days[13];
	static int _days_in_year;
    int _day;
    int _month;
    int _year;
};


} /* namespace Utils */

#endif /* UTILS_my_date_H_ */
