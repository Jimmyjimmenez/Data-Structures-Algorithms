#pragma once

#include "Set.h"

#include <string>

class Graph
{
public:

	Graph(int);
	~Graph();

	int cost(int, int);
	int totalVertex();

	void insert(int, int, int);

	static int* dijkstra(Graph);
	static Graph prim(Graph);
	static void minimumCostEdge(Graph, Set, Set, int&, int);
	static std::string printVector(std::string, int*, int);

	std::string print();
	std::string depth(int);
	
private:
	
	static const int INFINITE = std::numeric_limits<unsigned short int>::max();

	int vertices;
	int** edge;

	int vertexNotVisited(bool*, int);
	std::string depth(int, bool*&);
};

