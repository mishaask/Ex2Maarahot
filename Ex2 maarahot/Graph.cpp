//314085986
//mishaaskarov@gmail.com
#include "Graph.hpp"
#include <iostream>
#include <sstream>
namespace ariel {

void Graph::loadGraph(const std::vector<std::vector<int>>& adjacencyMatrix) {
    int size = adjacencyMatrix.size();
    if (size != 0 && size == adjacencyMatrix[0].size()) {
        matrix = adjacencyMatrix;
       // std::cout << "Graph loaded successfully." << std::endl;
    } else {
        throw std::invalid_argument("Invalid graph: The graph is not a square matrix.");
    }
}

std::string Graph::printGraph() const {
    size_t size = matrix.size();
    std::stringstream ss;
    for (size_t i = 0; i < size; ++i) {
        ss << "[";
        for (size_t j = 0; j < size; ++j) {
            ss << matrix[i][j];
            if (j != size - 1) {
                ss << ", ";
            }
        }
        ss << "]";
        if (i != size - 1) {
            ss << "\n";
        }
    }
    return ss.str();
}

// void Graph::printGraph() const {
//     size_t size = matrix.size();
//     std::cout << "Graph with " << size << " vertices and ";
//     size_t edges = 0;
//     for (size_t i = 0; i < size; ++i) {
//         for (size_t j = 0; j < size; ++j) {
//             if (matrix[i][j] != 0) {
//                 ++edges;
//             }
//         }
//     }
//     std::cout << edges << " edges." << std::endl;
// }
Graph Graph::operator+(const Graph& other) const {
    if (matrix.size() != other.matrix.size()) {
        throw std::invalid_argument("Graphs must be of the same size for addition.");
    }
    Graph result = *this;
    for (size_t i = 0; i < matrix.size(); ++i) {
        for (size_t j = 0; j < matrix.size(); ++j) {
            result.matrix[i][j] += other.matrix[i][j];
        }
    }
    return result;
}

Graph Graph::operator+() const {
    return *this;
}

Graph& Graph::operator+=(const Graph& other) {
    if (matrix.size() != other.matrix.size()) {
        throw std::invalid_argument("Graphs must be of the same size for addition.");
    }
    for (size_t i = 0; i < matrix.size(); ++i) {
        for (size_t j = 0; j < matrix.size(); ++j) {
            matrix[i][j] += other.matrix[i][j];
        }
    }
    return *this;
}

Graph Graph::operator-() const {
    Graph result = *this;
    for (size_t i = 0; i < matrix.size(); ++i) {
        for (size_t j = 0; j < matrix.size(); ++j) {
            result.matrix[i][j] = -result.matrix[i][j];
        }
    }
    return result;
}

Graph Graph::operator-(const Graph& other) const {
    if (matrix.size() != other.matrix.size()) {
        throw std::invalid_argument("Graphs must be of the same size for subtraction.");
    }
    Graph result = *this;
    for (size_t i = 0; i < matrix.size(); ++i) {
        for (size_t j = 0; j < matrix.size(); ++j) {
            result.matrix[i][j] -= other.matrix[i][j];
        }
    }
    return result;
}

Graph& Graph::operator-=(const Graph& other) {
    if (matrix.size() != other.matrix.size()) {
        throw std::invalid_argument("Graphs must be of the same size for subtraction.");
    }
    for (size_t i = 0; i < matrix.size(); ++i) {
        for (size_t j = 0; j < matrix.size(); ++j) {
            matrix[i][j] -= other.matrix[i][j];
        }
    }
    return *this;
}

bool Graph::operator==(const Graph& other) const {
    return matrix == other.matrix;
}

bool Graph::operator!=(const Graph& other) const {
    return !(*this == other);
}

bool Graph::operator<(const Graph& other) const {
    if(*this == other){
        return false;
    }

    Graph temp = other;
    bool isContained = true;

    for (size_t i = 0; i < matrix.size(); ++i) {
        for (size_t j = 0; j < matrix.size(); ++j) {
            temp.matrix[i][j] -= matrix[i][j];

            if (temp.matrix[i][j] < 0) {
                isContained = false;
                break;
            }
        }
        if (!isContained) {
            break;
        }
    }

    if (isContained) {
        return true;
    }

    size_t thisEdges = countEdges();
    size_t otherEdges = other.countEdges();
    if (thisEdges != otherEdges) {
        return thisEdges < otherEdges;
    }

    return matrix < other.matrix;
}

bool Graph::operator<=(const Graph& other) const {
    return *this < other || *this == other;
}

bool Graph::operator>(const Graph& other) const {
    return !(*this <= other);
}

bool Graph::operator>=(const Graph& other) const {
    return !(*this < other);
}

Graph& Graph::operator++() {
    for (size_t i = 0; i < matrix.size(); ++i) {
        for (size_t j = 0; j < matrix[i].size(); ++j) {
            ++matrix[i][j];
        }
    }
    return *this;
}

Graph Graph::operator++(int) {
    Graph temp = *this;
    ++(*this);
    return temp;
}

Graph& Graph::operator--() {
    for (size_t i = 0; i < matrix.size(); ++i) {
        for (size_t j = 0; j < matrix[i].size(); ++j) {
            --matrix[i][j];
        }
    }
    return *this;
}

Graph Graph::operator--(int) {
    Graph temp = *this;
    --(*this);
    return temp;
}

Graph Graph::operator*(int scalar) const {
    Graph result = *this;
    for (size_t i = 0; i < result.matrix.size(); ++i) {
        for (size_t j = 0; j < result.matrix[i].size(); ++j) {
            result.matrix[i][j] *= scalar;
        }
    }
    return result;
}

Graph& Graph::operator*=(int scalar) {
    for (size_t i = 0; i < matrix.size(); ++i) {
        for (size_t j = 0; j < matrix[i].size(); ++j) {
            matrix[i][j] *= scalar;
        }
    }
    return *this;
}

Graph Graph::operator*(const Graph& other) const {
    if (matrix.size() != other.matrix.size()) {
        throw std::invalid_argument("Graphs must be of the same size for multiplication.");
    }
    size_t size = matrix.size();
    Graph result;
    result.matrix = std::vector<std::vector<int>>(size, std::vector<int>(size, 0));
    for (size_t i = 0; i < size; ++i) {
        for (size_t j = 0; j < size; ++j) {
            for (size_t k = 0; k < size; ++k) {
                result.matrix[i][j] += matrix[i][k] * other.matrix[k][j];
            }
        }
    }
    return result;
}

std::ostream& operator<<(std::ostream& os, const Graph& graph) {
    size_t size = graph.matrix.size();
    std::stringstream ss;
    for (size_t i = 0; i < size; ++i) {
        ss << "[";
        for (size_t j = 0; j < size; ++j) {
            ss << graph.matrix[i][j];
            if (j != size - 1) {
                ss << ", ";
            }
        }
        ss << "]";
        if(i != size-1)
        ss << ", ";
    }
    ss << "\n";
    os << ss.str();
    return os;
}

Graph Graph::operator/(int scalar) const {
    if (scalar == 0) {
        throw std::invalid_argument("Division by zero.");
    }
    Graph result = *this;
    for (size_t i = 0; i < matrix.size(); ++i) {
        for (size_t j = 0; j < matrix.size(); ++j) {
            result.matrix[i][j] /= scalar;
        }
    }
    return result;
}

Graph& Graph::operator/=(int scalar) {
    if (scalar == 0) {
        throw std::invalid_argument("Division by zero.");
    }
    for (size_t i = 0; i < matrix.size(); ++i) {
        for (size_t j = 0; j < matrix.size(); ++j) {
            matrix[i][j] /= scalar;
        }
    }
    return *this;
}

size_t Graph::countEdges() const {
    size_t edges = 0;
    for (size_t i = 0; i < matrix.size(); ++i) {
        for (size_t j = 0; j < matrix[i].size(); ++j) {
            if (matrix[i][j] != 0) {
                ++edges;
            }
        }
    }
    return edges;
}

}
