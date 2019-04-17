/*
	City for CSCI 23500 Hunter-CUNY. Project 04, Stack navigation of map.
	By Nick Szewczak (nickszewczak.com)
	template for readMap(), getCity(), isRoute() provided by Professor Tiziana Ligorio
*/

#ifndef RouteMap_
#define RouteMap_
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include "City.hpp"

class RouteMap
{
  public:
	/***************** Constructors ****************/
	RouteMap(std::string csvName);
	
	/***************** Accessors ****************/
	/**
	 @return a pointer to the city found at position, where
	 0 <= position <= n-1, and n is the number of cities,
	 and cities are stored in the same order in which they appear
	 in the input file
	 **/
	City* getCity(size_t position);
	City* getCityByName(std::string name);
	void  allCitiesOut();
	/***************** Kitchen Sink ****************/
	/**
		@param input_file_name of a csv file representing a route map where the first
		line is a comma-separated list of city names, and the remainder is a
		comma-separated list of city-pairs of the form A-B, indicating that B
		is adjacent to A (i.e. there is an arrow in the map going from A to B)
		@post this depends on your design, the input data representing the map must
		have been stored. Cities must be stored in the same order in which
		they are read from the input file**/
	bool readMap(std::string input_file_name);

	/**
		@return true if there is a route from origin to destination, false otherwise
		@post if a route is found from origin to destination, it will print it to
		standard output in the form ORIGIN -> ... -> DESTINATION
		**/
	bool isRoute(City* origin, City* destination); 
	void clearRouteString();
	void appendRouteOutput(std::string reveraddition);
	std::string getCorrectRoute();
	
  private:
	std::string route_output_;
	std::vector<City> cities_;
	/***************** Kitchen Sink ****************/
	bool routeRecursive(City* origin, City* destination);
	void evaluateCsvCell(std::string cell);
};

#include "RouteMap.cpp"
#endif
