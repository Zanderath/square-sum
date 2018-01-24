#pragma once

#include "Graph.h"
#include <algorithm>
#include <iostream>
#include <fstream>

class SquareSum : public Graph
{
	private:
		std::ofstream outputFile;
		void buildSquareSumGraph();
		bool isPerfectSquare(int n);
		bool isSafe(int v, const std::vector<int>& path, int pos);
		void printPath(std::vector<int> * path);
		bool hamiltonian(int vertices, std::vector<int> path, int position);

	public:
		SquareSum(int vertices);
		void checkHamiltonianness(int vertices);
		~SquareSum();
};