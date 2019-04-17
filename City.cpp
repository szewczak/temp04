/*
	City for CSCI 23500 Hunter-CUNY. Project 04, Stack navigation of map.
	By Nick Szewczak (nickszewczak.com)
	template for readMap(), getCity(), isRoute() provided by Professor Tiziana Ligorio
*/

#include "City.hpp"
#include <string>
#include <vector>
#include <algorithm>

City::City(std::string CityName)
{
	city_node_ = CityName;
	visited = false;
	city_edges_.clear();
}

bool City::cityVisited() const
{
	return visited;
}
void City::CityVisitedSet(bool state){
	visited = state;
}

std::string City::getCityName() const
{
	return city_node_;
}

std::string City::getCityEdges() const
{
	std::string temp = "";
	for (int i = 0; i < city_edges_.size(); i++)
	{
		if (i > 0)
		{
			temp = temp + ", ";
		}
		temp = temp + city_edges_[i]->getCityName();
	}
	return temp;
}

std::vector<City*> City::cityNeighbors()
{
	return city_edges_;
}

bool City::addEdge(City* node)
{
	// std::cout << "starting addEdge(" << node << ")" << std::endl;

	if (std::find(city_edges_.begin(), city_edges_.end(), node) != city_edges_.end())
	{
		/*city_edges_ contains node*/
		return false;
	}
	else
	{
		city_edges_.push_back(node);
		return true;
	}
}
void City::resetCity(){
	visited = false;
}