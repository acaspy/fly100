/*
 * city.h
 *
 *  Created on: Dec 28, 2016
 *      Author: tsnappir
 */

#ifndef GEO_CITY_H_
#define GEO_CITY_H_

#include <iostream>
#include <string>
#include <tr1/unordered_map>
#include <iostream>
#include <time.h>
#include <ctime>
#include <stdlib.h>
#include <sstream>


namespace geo {

class city {
public:
	city(std::string id, int date);
	city(const city& obj) : _id (obj._id) , _date(obj._date) {}
	const std::string getName() const {return _id;}
	std::string getFullName();
	virtual int getDate() {return _date;}
	virtual ~city();
	static city* getCity(std::string city);
	static std::tr1::unordered_map<std::string,city*> places;

protected:
	std::string _id;
	int _date;
};

 /* namespace geo */

}

#endif /* GEO_CITY_H_ */
