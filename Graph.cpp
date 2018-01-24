#include "Graph.h"

Graph::Graph(int vertices, bool directed) : _adjacencyList(std::vector<std::list<int>>(vertices + 1))
{
	_vertices = vertices;
	_directed = directed;
}

int Graph::getVertices()
{
	return _vertices;
}

void Graph::addEdge(int vertex1, int vertex2)
{
	_adjacencyList[vertex1].push_back(vertex2);

	if (!_directed)
		_adjacencyList[vertex2].push_back(vertex1);
}

void Graph::deleteEdge(int vertex1, int vertex2)
{
	_adjacencyList[vertex1].remove(vertex2);

	if (!_directed)
		_adjacencyList[vertex2].remove(vertex1);
}

bool Graph::hasEdge(int vertex1, int vertex2)
{
	std::list<int>::iterator findIt = std::find(_adjacencyList[vertex1].begin(), _adjacencyList[vertex1].end(), vertex2);
	return findIt != _adjacencyList[vertex1].end();
}

Graph::~Graph()
{

}