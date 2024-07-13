#include "Graph.h"
#include <iostream>
#include <algorithm>
int Graph::numVertices() const {
    return vertexCount;
}

int Graph::numEdges() const {
    return edgeCount;
}

int Graph::indegree(int vertex) const {
    if (vertex >= vertexCount || vertex < 0) {
        std::cerr << "Invalid vertex index" << std::endl;
        return -1;
    }
    int inDeg = 0;
    for (int i = 0; i < vertexCount; ++i) {
        inDeg += adjMatrix[i][vertex];
    }
    return inDeg;
}

int Graph::outdegree(int vertex) const {
    if (vertex >= vertexCount || vertex < 0) {
        std::cerr << "Invalid vertex index" << std::endl;
        return -1;
    }
    int outDeg = 0;
    for (int j = 0; j < vertexCount; ++j) {
        outDeg += adjMatrix[vertex][j];
    }
    return outDeg;
}

int Graph::degree(int vertex) const {
    if (directed) {
        return indegree(vertex) + outdegree(vertex);
    } else {
        return outdegree(vertex); // Same as indegree in an undirected graph
    }
}

std::vector<int> Graph::neighbours(int vertex) const {
    if (vertex >= vertexCount || vertex < 0) {
        std::cerr << "Invalid vertex index" << std::endl;
        return std::vector<int>();
    }
    std::vector<int> neighbors;
    for (int i = 0; i < vertexCount; ++i) {
        if (adjMatrix[vertex][i] == 1) {
            neighbors.push_back(i);
        }
    }
    return neighbors;
}

bool Graph::neighbour(int vertex1, int vertex2) const {
    if (vertex1 >= vertexCount || vertex2 >= vertexCount || vertex1 < 0 || vertex2 < 0) {
        std::cerr << "Invalid vertex index" << std::endl;
        return false;
    }
    return adjMatrix[vertex1][vertex2] == 1;
}
