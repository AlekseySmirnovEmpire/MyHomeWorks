#include "MatrixGraph.h"
#include "Support.h"
#include <iostream>

void MatrixGraph::checkVertex(const int& input) 
{
	if (position.find(input) == position.end()) 
	{
		position.emplace(input, static_cast<int>(vertices.size()));
		vertices.push_back(input);
	}
}

MatrixGraph::MatrixGraph(const IGraph& other) 
{
	matrix.clear();
	vertices.clear();
	position.clear();

	for (const auto& elem1 : other.Vertices())
		for (const auto& elem2 : other.GetNextVertices(elem1))
			AddEdge(elem1, elem2);
}

int MatrixGraph::VerticesCount() const 
{
	return static_cast<int>(vertices.size());
}

void MatrixGraph::AddEdge(const int& from, const int& to) 
{
	checkVertex(from);
	checkVertex(to);

	if(matrix.size() != static_cast<int>(vertices.size()))
	{
		matrix.resize(static_cast<int>(vertices.size()));

		for(auto& elem : matrix) 
		{
			if (elem.size() != static_cast<int>(vertices.size()))
				elem.resize(static_cast<int>(vertices.size()));
		}
	}

	matrix[position.find(from)->second][position.find(to)->second] = true;
}

std::vector<int> MatrixGraph::Vertices() const
{
	return vertices;
}

std::vector<int> MatrixGraph::GetNextVertices(const int& vertex) const 
{
	std::vector<int> output;

	if (position.find(vertex) == position.end())
		return output;
	else 
	{
		int i(position.find(vertex)->second);

		for (int j = 0; j < matrix[i].size(); ++j)
			if (matrix[i][j] == 1)
				output.push_back(vertices[j]);
	}

	return output;
}

std::vector<int> MatrixGraph::GetPrevVertices(const int& vertex) const 
{
	std::vector<int> output;

	if (position.find(vertex) == position.end())
		return output;
	else
	{
		int i(position.find(vertex)->second);

		for (int j = 0; j < matrix[i].size(); ++j)
			if (matrix[i][j] == 1)
				output.push_back(vertices[j]);
	}

	return output;
} // по идее они получаются одинаковыми, учитывая как я записал первую, да?

void MatrixGraph::showGraph() 
{
	for (const auto& elem1 : matrix) 
	{
		for (const auto& elem2 : elem1)
			std::cout << elem2 << " ";

		std::cout << std::endl;
	}		
}