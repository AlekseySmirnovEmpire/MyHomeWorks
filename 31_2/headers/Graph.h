#pragma once
#include <vector>
#include <map>

class IGraph {

public:
	virtual ~IGraph() {}

	IGraph() {}; 
	IGraph(const IGraph& other) {}; 

	virtual void AddEdge(const int& from, const int& to) = 0; // Метод принимает вершины начала и конца ребра и добавляет ребро
	virtual int VerticesCount() const = 0; // Метод должен считать текущее количество вершин
	virtual std::vector<int> Vertices() const = 0; // Метод должен вернуть текущие список текущих вершин
	virtual std::vector<int> GetNextVertices(const int& vertex) const = 0; // Для конкретной вершины метод возвращает вектор с вершинами, в которые можно дойти по ребру из данной
	virtual std::vector<int> GetPrevVertices(const int& vertex) const = 0; // Для конкретной вершины метод возвращает вектор с вершинами, из которых можно дойти по ребру в данную

	virtual void showGraph() = 0;
};