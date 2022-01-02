#include "MatrixGraph.h"
#include "ListGraph.h"
#include "Support.h"
#include <iostream>

int main()
{
	ListGraph first;
	first.AddEdge(0, 4);
	first.AddEdge(0, 3);
	first.AddEdge(1, 2);
	first.AddEdge(1, 4);
	first.AddEdge(1, 5);
	first.AddEdge(2, 3);
	first.AddEdge(2, 5);
	first.AddEdge(5, 3);
	first.AddEdge(5, 4);

	first.showGraph();
	
	std::cout << std::endl;

	ListGraph second(first);
	second.showGraph();

	std::cout << std::endl;

	MatrixGraph third(second);
	third.showGraph();
}
