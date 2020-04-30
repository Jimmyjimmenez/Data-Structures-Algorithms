#include "Graph.h"

#include <sstream>

Graph::Graph(int vertex)
{
	this->vertex = vertex;

	edge = new int* [vertex];

	for (int i{ 0 }; i < vertex; i++) edge[i] = new int[vertex];

	for (int i{ 0 }; i < vertex; i++) {
		for (int j{ 0 }; j < vertex; j++) {
			edge[i][j] = Graph::INFINITE;
		}
	}
}

Graph::~Graph()
{
}

int Graph::cost(int firstVertex, int secondVertex)
{
	return (firstVertex >= 1 && firstVertex <= vertex && secondVertex >= 1 && secondVertex <= vertex) ? edge[firstVertex - 1][secondVertex - 1] : Graph::INFINITE;
}

int Graph::totalVertex()
{
	int elements{ 0 };

	for (int i{ 0 }; i < vertex; i++) {
	}
}

void Graph::insert(int firstVertex, int secondVertex, int cost)
{
	if (firstVertex >= 1 && firstVertex <= vertex && secondVertex >= 1 && secondVertex <= vertex) edge[firstVertex - 1][secondVertex - 1] = cost;
}

int* Graph::dijkstra(Graph)
{
	return nullptr;
}

Graph Graph::prim(Graph)
{
	return;
}

void Graph::minimumCostEdge(Graph, Set, Set, int&, int)
{
}

std::string Graph::printVector(std::string, int*, int)
{
	return std::string();
}

std::string Graph::print()
{
	return std::string();
}

std::string Graph::depth(int start)
{
	std::stringstream ss;

	bool* visited = new bool[vertex];

	for (int i{ 0 }; i < vertex; i++) visited[i] = false;

	int vertex = start - 1;

	do {
		ss << "\n" << depth(vertex, visited);

		vertex = vertexNotVisited(visited, vertex);
	} while (vertex != -1);

	ss << "\n";

	return ss.str();
}

int Graph::vertexNotVisited(bool* visited, int vertex)
{
	for (int i{ 0 }; i < totalVertex(); i++) {
		if (edge[vertex] == edge[i]) return vertex;
	}
	return -1;
}

std::string Graph::depth(int vertex, bool*& visited)
{
	std::stringstream ss;

	visited[vertex];

	ss << vertex + 1 << " ";

	for (int i{ 0 }; i < vertex; i++) {
		if (edge[vertex][i] != Graph::INFINITE && !visited[i]) ss << depth(i, visited);
	}

	return ss.str();
}
