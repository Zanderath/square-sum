#include "SquareSum.h"

SquareSum::SquareSum(int vertices) : Graph(vertices, false)
{
	outputFile.open("SquareSum.txt");
	buildSquareSumGraph();
}

void SquareSum::buildSquareSumGraph()
{
	if (getVertices() > 0)
	{
		for (int i = 1; i <= getVertices(); i++)
		{
			for (int j = 1; j < i; j++)
			{
				if (isPerfectSquare(i + j))
				{
					addEdge(i, j);
				}
			}

			std::cout << "Square Sum Problem with " << i << " vertices" << std::endl;

			if (outputFile.is_open())
			{
				outputFile << "Square Sum Problem with " << i << " vertices" << std::endl;
				outputFile << "Hamiltonian Cycle\tHamiltonian Path" << std::endl;
			}

			checkHamiltonianness(i);

			if (outputFile.is_open())
			{
				outputFile << std::endl;
			}
		}
	}
}

bool SquareSum::isPerfectSquare(int n)
{
	if (n < 0)
		return false;
	int root(round(sqrt(n)));
	return n == root * root;
}

/*	This utility function is to check if adding vertex to the path is a valid option.
*	There are 2 reasons why vertex could not be added:
*		1. Vertex does not have an edge to the previously added vertex
*		2. Vertex has already been added to the path
*/
bool SquareSum::isSafe(int vertex, const std::vector<int>& path, int position)
{
	// Check if this vertex is an adjacent vertex of the previously	added vertex.
	if (!hasEdge(path[position - 1], vertex))
		return false;

	/* Check if the vertex has already been included.
	This step can be optimized by creating an array of size V */
	for (int i = 0; i < position; i++)
		if (path[i] == vertex)
			return false;

	return true;
}

// A utility function to print a path
void SquareSum::printPath(std::vector<int> * path)
{
	for (int i = 0; i < path->size(); i++)
	{
		if (outputFile.is_open())
		{
			outputFile << path->at(i) << " ";
		}
	}
}

/*	This function sets up the conditions to check for the different
 *	Hamiltonian paths and cycles in the graph for the subgraph that
 *	contains the first n number of vertices.
 */
void SquareSum::checkHamiltonianness(int vertices)
{
	std::vector<int> path(vertices);

	for (int i = 1; i <= vertices; i++)
	{
		std::transform(path.begin(), path.end(), path.begin(), [](int n) -> int { return -1; });
		path[0] = i;

		hamiltonian(vertices, path, 1);
	}
}

/*	This is a recursive function to determine if the subgraph of the first
 *	n number of vertices contains a Hamiltonian Path, and if that path
 *	creates a Hamiltonian Cycle.
 *
 *	Base Case:
 *		If the number of vertices added to the path equals the number of
 *		vertices in the subgraph we have successfully found a Hamiltonian
 *		Path.  For each path we will also check to see if there is an edge
 *		between the first and last position in the path.
 *	Recursive Case:
 *		Find the next valid vertex to add to the path, and add it to the
 *		path
 */
bool SquareSum::hamiltonian(int vertices, std::vector<int> path, int position)
{
	//Base Case
	if (position == vertices)
	{
		//Check if the Hamiltonian Path is a Hamiltonian Cycle
		if (hasEdge(path[position - 1], path[0]))
		{
			if (outputFile.is_open())
			{
				outputFile << "True\t\t\t\t";
			}
		}
		else
		{
			if (outputFile.is_open())
			{
				outputFile << "False\t\t\t\t";
			}
		}

		printPath(&path);
		if (outputFile.is_open())
		{
			outputFile << std::endl;
		}

		return true;
	}

	//Recursive Case
	for (int v = 1; v <= vertices; v++)
	{
		//Check if this vertex can be added to Hamiltonian Cycle 
		if (isSafe(v, path, position))
		{
			path[position] = v;

			if (hamiltonian(vertices, path, position + 1) == false)
			{
				//If adding vertex v doesn't lead to solution remove it
				path[position] = -1;
				return false;
			}

		}
	}

	return true;
}

SquareSum::~SquareSum()
{
	outputFile.close();
}