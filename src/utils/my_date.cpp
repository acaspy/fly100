/*
 * my_date.cpp
 *
 *  Created on: Feb 22, 2017
 *      Author: tsnappir
 */

#include "my_date.h"

namespace DateUtils {

int my_date::_month_days[] = {0, 31, 28, 31, 30, 31, 30 , 31, 31 , 30, 31, 30, 31};
int my_date::_days_in_year = 365;

my_date::my_date(int my_date) {
	 _day = my_date % 100;
	 my_date /= 100;
	 _month = my_date %100;
	 my_date /= 100;
	 _year = my_date;
}

my_date::~my_date() {
	// TODO Auto-generated destructor stub
}

int my_date::operator-(my_date& d1) {
	int counter = 0;
	int d = d1.getDay();
	int m = d1.getMonth();
	int y = d1.getYear();

	if (_day < d) {
		d -= _month_days[m++];
	}
	if (m==13) {
		m=1;
		y++;
	}
	counter += _day-d;
	while (m<_month) {
		counter += _month_days[m++];
		if (m==13) {
			m=1;
			y++;
		}
	}
	while( y < _year) {
		counter+=365;
	}

	return counter;
}

void my_date::operator+(int days) {
	while (days>_days_in_year) {
		_days_in_year-=360;
		_year++;
	}
	while (_day + days>_month_days[_month]) {
		days -= _month_days[_month++];
		if (_month == 13) {
			_month = 1;
			_year++;
		}
	}
	_day+=days;
}

int my_date::getNextDate(int days) {
	int year = _year;
	int month = _month;
	int day = _day;
	while (days>_days_in_year) {
		_days_in_year-=360;
		year++;
	}
	while (day + days>_month_days[month]) {
		days -= _month_days[month++];
		if (month == 13) {
			month = 1;
			year++;
		}
	}
	return year*10000+month*100+day+days;
}


int my_date::getPrevDate(int days) {
	int year = _year;
	int month = _month;
	int day = _day;
	while (days>_days_in_year) {
		_days_in_year-=360;
		year--;
	}
	while (day <= days) {
		day += _month_days[--month];
	}
	return year*10000+month*100+day-days;
}


} /* namespace Utils */
