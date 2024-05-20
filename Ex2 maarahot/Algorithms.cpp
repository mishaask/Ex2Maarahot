//314085986
//mishaaskarov@gmail.com
#include "Algorithms.hpp"
#include <queue>
#include <vector>
#include <unordered_set>
#include <stack>
#include <climits>
#include <algorithm>
#include <iostream>
#include <limits>


namespace ariel {


bool Algorithms::isConnected(const Graph& graph) {
    // Perform DFS from every vertex
    for (size_t i = 0; i < graph.matrix.size(); ++i) {
        std::vector<bool> visited(graph.matrix.size(), false);
        std::stack<size_t> stack;
        stack.push(i);
        visited[i] = true;

        while (!stack.empty()) {
            size_t current = stack.top();
            stack.pop();

            for (size_t j = 0; j < graph.matrix.size(); ++j) {
                if (graph.matrix[current][j] != 0 && !visited[j]) {
                    stack.push(j);
                    visited[j] = true;
                }
            }
        }

        // If any vertex is unreachable, return false
        for (size_t j = 0; j < graph.matrix.size(); ++j) {
            if (!visited[j]) {
                return false;
            }
        }
    }

    return true;
}

bool Algorithms::hasNegativeCycle(const Graph& graph) {
    size_t size = graph.matrix.size();
    std::vector<int> distance(static_cast<size_t>(size), 0);

    // Relax all edges |V| - 1 times
    for (size_t i = 0; i < size - 1; ++i) {
        for (size_t u = 0; u < size; ++u) {
            for (size_t v = 0; v < size; ++v) {
                if (graph.matrix[u][v] != 0 && distance[u] + graph.matrix[u][v] < distance[v]) {
                    distance[v] = distance[u] + graph.matrix[u][v];
                }}}}

    // Check for negative-weight cycles
    for (size_t u = 0; u < size; ++u) {
        for (size_t v = 0; v < size; ++v) {
            if (graph.matrix[u][v] != 0 && distance[u] + graph.matrix[u][v] < distance[v]) {
                return true; // Negative cycle found
            }}}

    return false;
}

std::string Algorithms::shortestPath(const Graph& graph, size_t start, size_t end) {

        if(graph.matrix.size() == 0)
        return "-1";

        std::vector<int> distance(graph.matrix.size(), std::numeric_limits<int>::max());
        std::vector<int> predecessor(graph.matrix.size(), -1);
        distance[start] = 0;

        if(start == end)
        return "Same start and end points";

        else if(start<end){// for example path from 0 ->2
        for (size_t relaxcycle = 0; relaxcycle < graph.matrix.size() - 1; ++relaxcycle) {//number of relaxes
            for (size_t uvec = start; uvec < graph.matrix.size(); ++uvec) {//u is a vec
                for (size_t vneigh = 0; vneigh < graph.matrix.size(); ++vneigh) {//v is u's "neighbor" being checked
                int edgeW = graph.matrix[uvec][vneigh];
                    if (edgeW != 0 && distance[uvec] + edgeW < distance[vneigh]) {
                        distance[vneigh] = distance[uvec] + edgeW;
                        predecessor[vneigh] = uvec;
                    }
                }
            }
            for (size_t uvec = 0; uvec < start; ++uvec) {//u is a vec
                for (size_t vneigh = 0; vneigh < graph.matrix.size(); ++vneigh) {//v is u's "neighbor" being checked
                int edgeW = graph.matrix[uvec][vneigh];
                    if (edgeW != 0 && distance[uvec] + edgeW < distance[vneigh]) {
                        distance[vneigh] = distance[uvec] + edgeW;
                        predecessor[vneigh] = uvec;
                    }
                }
            }
        }
        // Check for negative-weight cycles
        for (size_t u = start; u < graph.matrix.size(); ++u) {
            for (size_t v = 0; v < graph.matrix.size(); ++v) {
                if (graph.matrix[u][v] != 0 && distance[u] + graph.matrix[u][v] < distance[v]) {
                    return "-1";}}}

        for (size_t u = 0; u < start; ++u) {
            for (size_t v = 0; v < graph.matrix.size(); ++v) {
                if (graph.matrix[u][v] != 0 && distance[u] + graph.matrix[u][v] < distance[v]) {
                    return "-1";}}}

        }else{// for example path from 2->0
        for (size_t relaxcycle = 0; relaxcycle < graph.matrix.size() - 1; ++relaxcycle) {//number of relaxes
            for (size_t uvec = start; uvec > 0; --uvec) {
                for (size_t vneigh = 0; vneigh < graph.matrix.size(); ++vneigh) {
                int edgeW = graph.matrix[uvec][vneigh];
                    if (edgeW != 0 && distance[uvec] + edgeW < distance[vneigh]) {
                        distance[vneigh] = distance[uvec] + edgeW;
                        predecessor[vneigh] = uvec;
                    }
                }
            }
            //for some reason the previous for loop kept decreasing u to be lower then 0 if i wrote size_t u = start; u >= 0; --u (as i checked while debbugin)
            for (size_t vneigh = 0; vneigh < graph.matrix.size(); ++vneigh) {
                int edgeW = graph.matrix[0][vneigh];
                    if (edgeW != 0 && distance[0] + edgeW < distance[vneigh]) {
                        distance[vneigh] = distance[0] + edgeW;
                        predecessor[vneigh] = 0;
                    }
            }

            for (size_t uvec = graph.matrix.size() - 1; uvec > start; --uvec) {
                for (size_t vneigh = 0; vneigh < graph.matrix.size(); ++vneigh) {
                int edgeW = graph.matrix[uvec][vneigh];
                    if (edgeW != 0 && distance[uvec] + edgeW < distance[vneigh]) {
                        distance[vneigh] = distance[uvec] + edgeW;
                        predecessor[vneigh] = uvec;
                    }
                }
            }

        }
        // Check for negative-weight cycles
        for (size_t u = start; u > 0; --u) {
            for (size_t v = 0; v < graph.matrix.size(); ++v) {
                if (graph.matrix[u][v] != 0 && distance[u] + graph.matrix[u][v] < distance[v]) {
                    return "-1"; 
                }
            }
        }
        //for some reason the previous for loop kept decreasing u to be lower then 0 if i wrote size_t u = start; u >= 0; --u (as i checked while debbugin)
        for (size_t v = 0; v < graph.matrix.size(); ++v) {
                if (graph.matrix[0][v] != 0 && distance[0] + graph.matrix[0][v] < distance[v]) {
                    return "-1"; 
                }
            }
        for (size_t u = graph.matrix.size() - 1; u > start; --u) {
            for (size_t v = 0; v < graph.matrix.size(); ++v) {
                if (graph.matrix[u][v] != 0 && distance[u] + graph.matrix[u][v] < distance[v]) {
                    return "-1";
                }
            }
        }
        }


        if (distance[end] == std::numeric_limits<int>::max()){
        return "-1";}


        // Construct the path.
        std::stack<size_t> path;
        size_t current = end;
        size_t tries = 0;//can t have a path longer then number of vectors whitout having a cycle(which wont be the shortest path)
        while (current != start) {
            path.push(current);
            current = static_cast<size_t>(predecessor[current]);
            if(tries > graph.matrix.size())
            return "-1";
            tries ++;
        }
        path.push(start);


        // Format the path as a string.
        std::string result;
        while (!path.empty()) {
            result += std::to_string(path.top());
            path.pop();
            if (!path.empty()) {
                result += "->";
            }
        }

        return result;
    }

bool Algorithms::isContainsCycle(const Graph& graph) {
    int size = static_cast<int>(graph.matrix.size());
    std::vector<bool> visited(static_cast<size_t>(size), false);
    std::vector<int> parent(static_cast<size_t>(size), -1); // To store parent of each vertex in DFS tree

    for (int i = 0; i < size; ++i) {
        if (!visited[static_cast<size_t>(i)]) {
            std::stack<int> stack;
            stack.push(i);
            while (!stack.empty()) {
                int current = stack.top();
                stack.pop();

                if (visited[static_cast<size_t>(current)]) {
                    // Cycle detected, reconstruct and print the cycle
                    std::vector<int> cycle;
                    cycle.push_back(current);
                    for (int v = parent[static_cast<size_t>(current)]; v != -1 && v != current; v = parent[static_cast<size_t>(v)]) {
                        cycle.push_back(v);
                    }
                    cycle.push_back(current);

                    if (cycle.size() > 2) {
                        // Print the cycle in the correct order
                        std::cout << "The cycle is: ";
                        for (int j = static_cast<int>(cycle.size()) - 1; j > 0; --j) {
                            std::cout << cycle[static_cast<size_t>(j)] << "->";
                        }
                        std::cout << cycle[0] << std::endl;

                        return true;
                    }
                }

                visited[static_cast<size_t>(current)] = true;
                for (int j = 0; j < size; ++j) {
                    if (graph.matrix[static_cast<size_t>(current)][static_cast<size_t>(j)] != 0 && !visited[static_cast<size_t>(j)]) {
                        stack.push(j);
                        parent[static_cast<size_t>(j)] = current;
                    }
                }
            }
        }
    }

    return false;
}

std::string Algorithms::isBipartite(const Graph& graph) {
    size_t size = graph.matrix.size();
    std::vector<int> color(size, -1);
    std::queue<int> q;

    for (size_t i = 0; i < size; ++i) {
        if (color[i] == -1) {
            q.push(i);
            color[i] = 0;
            while (!q.empty()) {
                int u = q.front();
                q.pop();
                for (size_t v = 0; v < size; ++v) {
                    if (graph.matrix[(size_t)u][v] != 0) {
                        if (color[v] == -1) {
                            color[v] = 1 - color[(size_t)u];
                            q.push(v);
                        } else if (color[v] == color[(size_t)u]) {
                            return "0"; // Not bipartite
                        }
                    }
                }
            }
        }
    }

    // Construct the bipartition sets
    std::vector<int> setA, setB;
    for (size_t i = 0; i < size; ++i) {
        if (color[i] == 0) {
            setA.push_back(i);
        } else {
            setB.push_back(i);
        }
    }

    // Sort the sets
    std::sort(setA.begin(), setA.end());
    std::sort(setB.begin(), setB.end());

    // Construct the result string
    if (setA.empty() || setB.empty()) {
        return "0"; // Not bipartite
    }

    std::string result = "The graph is bipartite: A={";
    for (size_t i = 0; i < setA.size(); ++i) {
        result += std::to_string(setA[i]);
        if (i != setA.size() - 1) {
            result += ", ";
        }
    }
    result += "}, B={";
    for (size_t i = 0; i < setB.size(); ++i) {
        result += std::to_string(setB[i]);
        if (i != setB.size() - 1) {
            result += ", ";
        }
    }
    result += "}";

    return result;
}
} // namespace ariel
