          -Graph Algorithms Implementation-

This C++ project implements several algorithms for working with graphs. 
The implementation includes:

*Loading a graph from an adjacency matrix.
*Checking if a graph is connected.
*Finding the shortest path between two nodes.
*Detecting cycles in a graph.
*Checking if a graph is bipartite.
*Detecting negative cycles in a graph.


                     -Files-

Graph.hpp and Graph.cpp: Implement a class for representing a graph and method for loading and printing graphs.

Algorithms.hpp and Algorithms.cpp: Implements various algorithms for graph operations.


              -Building the Project-

To build the project, use the provided Makefile. 
*Run "make all" to compile the demo executable and the test executable.
*Run "make test" to compile the test executable. 
*Run "make demo" to compile the demo executable. 
*Run "make run" to execute the test and then execute demo., and make test to run the unit tests.


              -Methods in Algorithms.cpp-

*isConnected(const Graph& graph): This method checks if a graph is connected. It performs a Depth-First Search (DFS) from every vertex in the graph. If any vertex is unreachable, the method returns false, indicating that the graph is not connected. Otherwise, it returns true.

*hasNegativeCycle(const Graph& graph): This method checks if a graph has a negative cycle. It uses the Bellman-Ford algorithm to detect negative-weight cycles. It relaxes all edges |V| - 1 times and then checks for any further relaxation. If there is a negative-weight cycle, the method returns true; otherwise, it returns false.

*shortestPath(const Graph& graph, size_t start, size_t end): This method finds the shortest path between two vertex in a graph using the Bellman-Ford algorithm. It relaxes edges |V| - 1 times starting from the start node and then checks for negative-weight cycles. If there is a path from the start node to the end node, the method returns the path as a string. If there is no path or a negative-weight cycle, it returns "-1".

*isContainsCycle(const Graph& graph): This method checks if a graph contains a cycle. It uses a modified DFS approach to traverse the graph and detect cycles. If a cycle is found, the method returns true and prints the cycle; otherwise, it returns false.

*isBipartite(const Graph& graph): This method checks if a graph is bipartite. It assigns colors (0 and 1) to vertices using a BFS approach. If adjacent vertices have the same color, the graph is not bipartite, and the method returns "0". If the graph is bipartite, it constructs and returns a string indicating the bipartition sets A and B.


              -Methods in Graph.cpp-

*loadGraph(const std::vector<std::vector<int>>& adjacencyMatrix): This method loads a graph from an adjacency matrix. It checks if the matrix is square (i.e., the number of rows is equal to the number of columns) and non-empty. If the matrix meets these conditions, it assigns the matrix to the matrix member variable of the Graph class. Otherwise, it throws an std::invalid_argument exception with the message "Invalid graph: The graph is not a square matrix."

*printGraph() const: This method prints information about the graph. It first determines the number of vertices in the graph based on the size of the matrix. Then, it iterates over all elements of the matrix to count the number of edges (non-zero entries). Finally, it prints the number of vertices and edges in the graph.



