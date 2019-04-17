/*
	City for CSCI 23500 Hunter-CUNY. Project 04, Stack navigation of map.
	By Nick Szewczak (nickszewczak.com)
	template for readMap(), getCity(), isRoute() provided by Professor Tiziana Ligorio
*/

#include "RouteMap.hpp"
#include "City.hpp"

bool RouteMap::isRoute(City* origin, City* destination)
{
	for(int i=0;i<cities_.size();i++){
		cities_[i].resetCity();
		clearRouteString();
	}
	if(routeRecursive(origin, destination)){
		std::cout << getCorrectRoute();
		return true;
	}
	else{
		std::cout << "no route found" << std::endl;
		return false;
	}
}



bool RouteMap::routeRecursive(City* origin, City* destination){
	// check if destination
		// if dest. print City.name
		// return true
	// check neghbors for 'unvisited'
		// recursive call these neighbors
		// if R.call true
	// print City.name " -> "
	// return calls t/f ORRED
	// std::cout << "routeRecursive Call with Origin `"<< origin->getCityName() << "` and dest `" << destination->getCityName() << "`" << std::endl;// debug
	if(origin->getCityName() == destination->getCityName()){					// if origin == destination
		std::string out = destination->getCityName();
		// std::cout << "`" << origin->getCityName() << "\tflag, found destination`" << std::endl;	// debug
		appendRouteOutput(out);
		return true;															// base case
	}
	origin->CityVisitedSet(true);												// if not base case, set city visited
	bool temp = false;															// for loop break variable
	City* nearbyPtr;
	for(int i=0; i<origin->cityNeighbors().size();i++){
		nearbyPtr = origin->cityNeighbors()[i];									// ptr peeks nth item in city_edges_
		if(!nearbyPtr->cityVisited()){											// if node has not been visited
			if(routeRecursive(nearbyPtr, destination)){							// recrusive call. if successful push this node to route_output
				// std::cout << "`route" << origin->getCityName() << "`" << std::endl;
				std::string out = " >- " + origin->getCityName();
				appendRouteOutput(out);
				return true;													// route has found desitination, no other edges need to be traversed
			}
		}																		// loop tries next edge
	}
	return false;

}

std::string RouteMap::getCorrectRoute()
{
	std::string unReversed = "";
	for(int i = route_output_.length()-1; i >= 0; i--)
	{
		unReversed += route_output_[i];
	}
	unReversed += "\n";
	return unReversed;
}

RouteMap::RouteMap(std::string csvName)
{
	if(!readMap(csvName)){
		std::cout << "catching" << std::endl;
	}
}

bool RouteMap::readMap(std::string input_file_name)
{
	std::fstream csv_file;
	csv_file.open(input_file_name);
	std::string temp;
	std::string dash = "-";
	bool errout = false;
	while (std::getline(csv_file, temp))
	{ // read line to temp
		if ((temp.substr((temp.length() - 1), 1)) == "\r")
		{ //
			temp = temp.substr(0, temp.length() - 1);
		}
		if ((temp.substr((temp.length() - 1), 1)) == "\n")
		{
			temp = temp.substr(0, temp.length() - 1);
		}
		// std::cout << "last character: `" << temp.substr((temp.length()-1),1) << "`..." << std::endl;
		std::istringstream linestream(temp);
		while (std::getline(linestream, temp, ','))
		{
			errout = true;
			if (temp.length() != 0)
			{ // ignore empty cells
				// std::cout << "\tthis cell is `" << temp << "`" << std::endl;
				evaluateCsvCell(temp);
			}
		}
	}	
	return errout;
}

void RouteMap::appendRouteOutput(std::string reveraddition)
{
	route_output_ += reveraddition;
}

void RouteMap::clearRouteString()
{
	route_output_ = "";
}

void RouteMap::allCitiesOut()
{
	std::cout << "cities currently in cities_:" << std::endl;
	for (int i = 0; i < cities_.size(); i++)
	{
		std::cout << cities_[i].getCityName() << "\t" << cities_[i].getCityEdges() << std::endl;
	}
}

City *RouteMap::getCityByName(std::string name)
{
	// std::cout << "\t\tgetCityByName(" << name << ")" << std::endl;
	for (int i = 0; i < cities_.size(); i++)
	{
		if (name == cities_[i].getCityName())
		{
			// this is the index of the city we are looking for
			return &(cities_[i]);
		}
	}
	return nullptr;
}

void RouteMap::evaluateCsvCell(std::string cell)
{
	// std::cout << "evaluateCsvCell(" << cell << ")" << std::endl; //debug
	size_t dashPos = cell.find("-");
	if (dashPos == std::string::npos)
	{
		// this is a new city designator
		// add city to cities_
		cities_.push_back(City(cell));
		// std::cout << "New citty added:" << std::endl;
		// for(int i=0; i < cities_.size();i++){
		// 	std::cout << "\t" << cities_[i].getCityName() << std::endl;
		// }

	}
	else
	{
		// std::cout << "new path: `" << cell << "`" << std::endl;					// debug
		City *targetPtr = getCityByName(cell.substr(0, dashPos));					// pointer to the city we are adding an edge to
		int target_length = cell.length() - dashPos - 1;							// length of the target city string
		// std:: cout << "\tthis city is (by ptr) `" << targetPtr->getCityName() << std::endl; 
		targetPtr->addEdge(getCityByName(cell.substr(dashPos+1, target_length)));	// find pointer to city that we are connecting via edge, add it former's city_edges_
	}
}

City *RouteMap::getCity(size_t position)
{
	return &(cities_[position]);
}
