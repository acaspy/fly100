/*
 * city.cpp
 *
 *  Created on: Dec 28, 2016
 *      Author: tsnappir
 */

#include "city.h"

namespace geo {

std::tr1::unordered_map<std::string,city*> city::places;

city::city(std::string id, int date) : _id(id), _date(date) {
	city::places[this->getFullName()] = this;
}

city::~city() {
	city::places.erase(this->getFullName());
}

city* city::getCity(std::string city) {
	if (city::places.count(city) == 1) {
		return city::places[city];
	}
	return 0;
}

std::string city::getFullName() {
	std::string d = static_cast<std::ostringstream*>( &(std::ostringstream() << _date) )->str();
	 return _id + "_" + d;
}


} /* namespace geo */
