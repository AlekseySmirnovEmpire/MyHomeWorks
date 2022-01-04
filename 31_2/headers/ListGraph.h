#pragma once
#include "Graph.h"
#include <map> 

class ListGraph : public IGraph
{
private:
	std::map<int, std::vector<int>> vertexIn;
	std::map<int, std::vector<int>> vertexOut;

public:
	ListGraph() {};
	ListGraph(const IGraph& other);

	~ListGraph() override {};

	void AddEdge(const int& from, const int& to) override;
	int VerticesCount() const override;
	std::vector<int> Vertices() const override;
	std::vector<int> GetNextVertices(const int& vertex) const override;
	std::vector<int> GetPrevVertices(const int& vertex) const override;

	void showGraph();
};