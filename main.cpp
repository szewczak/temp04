/*
	CSCI 23500 Hunter-CUNY. Project 04, Stack navigation of map.
	By Nick Szewczak (nickszewczak.com)
*/

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <iostream>
#include "City.hpp"
#include "RouteMap.hpp"

using namespace std;

int main()
{
	// /*Simple testing*/
	// cout << "test" << endl;
	// City bar("nyc");
	// bar.addEdge("dc");
	// bar.addEdge("hell");
	// vector<string> nearby = bar.cityNeighbors();
	// for (int i = 0; i < nearby.size(); i++)
	// {
	// 	cout << nearby[i] << endl;
	// }
	RouteMap foo("linuxonly.csv");
	cout << endl;
	foo.allCitiesOut();
	City * start = foo.getCityByName("A");
		cout << "City* start is named `" << start->getCityName() << "`"<< endl;
	City * end = foo.getCityByName("P");
		cout << "City* end is named `" << end->getCityName() << "`"<< endl;
	cout << "calling isRoute("<< start->getCityName() << ", " << end->getCityName() << ")";
	if(foo.isRoute(start, end)){
		cout << "\troute found" << endl;
	}
	else cout << "\tno route found" << endl;
	return 0;
}



// /nL <- I <- H <- F <- C <- A