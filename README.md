# square-sum
The code presented here is inspired by the Numberphile video about the Square Sum Problem as presented by Matt Parker (https://youtu.be/G1m7goLCJDY).
Part of my goal was to practice my C++ skills.
I modified the code found here (http://www.technical-recipes.com/2015/determining-if-paths-are-hamiltonian-in-c/) which is itself a modification of the code found here (https://www.geeksforgeeks.org/backtracking-set-7-hamiltonian-cycle/).
Other than modifying the code to refresh some concepts for myself, the big change to the code was to change the primary focus to look for Hamiltonian Paths instead of Hamiltonian cycles.  From a Hamiltonian Path I could then check if there is an edge in the graph between the first and last vertex in the path in order to determine if the path was a Hamiltonian Cycle.
Since I am just using the standard libraries I did not display the Square Sum graph visually.  Instead I have chose to print each Hamiltonian Path found to a text file.  I also print out if the path is also a cycle with a "true" or "false" string value.
When the code executes it will prompt the user for the number of vertices to check in the context of the Square Sum problem.  The program will check all graphs from 1 to n where n is the number of vertices indicated by the user.
