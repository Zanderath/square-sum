#pragma once
#include <vector>
#include <list>

class Graph
{
	private:
		int _vertices; //The maximum number of vertices for the graph
		bool _directed; //Value to determine if the graph is directed or not
		std::vector<std::list<int>> _adjacencyList; //An adjacency list to represent the graph

	public:
		Graph(int Vertices, bool Directed = false);
		int getVertices();
		void addEdge(int Vertex1, int Vertex2);
		void deleteEdge(int Vertex1, int Vertex2);
		bool hasEdge(int Vertex1, int Vertex2);
		~Graph();
};