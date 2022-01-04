#include "ListGraph.h"
#include "Support.h"
#include <iostream>

void addNewEdges(std::map<int, std::vector<int>>& map, const int& to, const int& from)
{
	bool isFound = false;

	auto it = map.find(to);

	for (const auto& element : it->second)
		if (element == from) 
		{
			isFound = true;
			break;
		}			

	if (!isFound)
		it->second.push_back(from);
}

void checkVertex(std::map<int, std::vector<int>>& mapIn, std::map<int, std::vector<int>>& mapOut, const int& input)
{
	if(mapIn.find(input) == mapIn.end())
		mapIn.emplace(input, 0);
	if (mapOut.find(input) == mapOut.end())
		mapOut.emplace(input, 0);
}

ListGraph::ListGraph(const IGraph& other) 
{
	vertexIn.clear();
	vertexOut.clear();

	for(const auto& elem : other.Vertices()) 
	{
		vertexOut.emplace(elem, other.GetNextVertices(elem));
		vertexIn.emplace(elem, other.GetPrevVertices(elem));
	}
}

int ListGraph::VerticesCount() const 
{
	return static_cast<int>(vertexIn.size());
}

void ListGraph::AddEdge(const int& from, const int& to) 
{
	checkVertex(vertexIn, vertexOut, from);
	checkVertex(vertexIn, vertexOut, to);

	addNewEdges(vertexOut, from, to);
	addNewEdges(vertexIn, to, from);
}

std::vector<int> ListGraph::GetNextVertices(const int& vertex) const
{
	return vertexOut.find(vertex)->second;
}

std::vector<int> ListGraph::GetPrevVertices(const int& vertex) const 
{
	return vertexIn.find(vertex)->second;
}

void ListGraph::showGraph() 
{
	for (const auto& mapElement : vertexOut) 
	{
		std::cout << mapElement.first << " : ";
		
		for (const auto& element : mapElement.second)
			std::cout << element << " ";

		std::cout << std::endl;
	}
}

std::vector<int> ListGraph::Vertices() const 
{
	std::vector<int> temp;

	for (const auto& elem : vertexIn)
		temp.push_back(elem.first);

	return temp;
}