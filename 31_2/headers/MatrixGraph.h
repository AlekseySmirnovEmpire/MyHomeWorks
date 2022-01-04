#pragma once
#include "Graph.h"
#include <vector>

class MatrixGraph : public IGraph 
{
private:
	std::vector<std::vector<bool>> matrix; //сама матрица
	std::vector<int> vertices; //все вершины
	std::map<int, int> position; //кординаты всех вершин (первый инт - вершина, второй - координата)

public:
	MatrixGraph() {}
	MatrixGraph(const IGraph& other);

	~MatrixGraph() override {};

	void AddEdge(const int& from,const int& to) override;
	int VerticesCount() const override;
	std::vector<int> Vertices() const override;
	std::vector<int> GetNextVertices(const int& vertex) const override;
	std::vector<int> GetPrevVertices(const int& vertex) const override;

	void showGraph() override;

	void checkVertex(const int& input);
};