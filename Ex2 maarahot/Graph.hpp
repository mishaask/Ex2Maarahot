//314085986
//mishaaskarov@gmail.com
#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <vector>
#include <iostream>
namespace ariel{ 

class Graph {
public:
    void loadGraph(const std::vector<std::vector<int>>& adjacencyMatrix);
    std::string printGraph() const;
    std::vector<std::vector<int>> matrix;
    
    size_t countEdges() const;
    
    // +/-
    Graph operator+(const Graph& other) const;
    Graph operator+() const;
    Graph& operator+=(const Graph& other);
    Graph operator-() const;
    Graph operator-(const Graph& other) const;
    Graph& operator-=(const Graph& other);
    // =/</>
    bool operator==(const Graph& other) const;
    bool operator!=(const Graph& other) const;
    bool operator<(const Graph& other) const;
    bool operator<=(const Graph& other) const;
    bool operator>(const Graph& other) const;
    bool operator>=(const Graph& other) const;

    // ++/--1 , 1++/--
    Graph& operator++();    
    Graph operator++(int);  
    Graph& operator--();    
    Graph operator--(int);  

    // * scalar
    Graph operator*(int scalar) const;
    Graph& operator*=(int scalar);

    // * M
    Graph operator*(const Graph& other) const;

    // /M
    Graph operator/(int scalar) const;
    Graph& operator/=(int scalar);

    // output stream
    friend std::ostream& operator<<(std::ostream& os, const Graph& graph);
};

}

#endif /* GRAPH_HPP */
