#include "../include/graph.h"
#include <iostream>
#include <algorithm>
Graph::Graph(bool isDirected)
    : vertexCount(0), edgeCount(0), directed(isDirected) {}

bool Graph::isEmpty() const {
    return vertexCount == 0;
}

bool Graph::isDirected() const {
    return directed;
}

void Graph::addVertex() {
    vertexCount++;
    for (auto& row : adjMatrix) {
        row.push_back(0);
    }
    adjMatrix.push_back(std::vector<int>(vertexCount, 0));
}

void Graph::addEdge(int vertex1, int vertex2) {
    if (vertex1 >= vertexCount || vertex2 >= vertexCount || vertex1 < 0 || vertex2 < 0) {
        std::cerr << "Invalid vertex index" << std::endl;
        return;
    }
    if (adjMatrix[vertex1][vertex2] == 0) {
        adjMatrix[vertex1][vertex2] = 1;
        edgeCount++;
        if (!directed) {
            adjMatrix[vertex2][vertex1] = 1;
        }
    }
}

void Graph::removeVertex(int vertex) {
    if (vertex >= vertexCount || vertex < 0) {
        std::cerr << "Invalid vertex index" << std::endl;
        return;
    }
    adjMatrix.erase(adjMatrix.begin() + vertex);
    for (auto& row : adjMatrix) {
        row.erase(row.begin() + vertex);
    }
    vertexCount--;
}

void Graph::removeEdge(int vertex1, int vertex2) {
    if (vertex1 >= vertexCount || vertex2 >= vertexCount || vertex1 < 0 || vertex2 < 0) {
        std::cerr << "Invalid vertex index" << std::endl;
        return;
    }
    if (adjMatrix[vertex1][vertex2] == 1) {
        adjMatrix[vertex1][vertex2] = 0;
        edgeCount--;
        if (!directed) {
            adjMatrix[vertex2][vertex1] = 0;
        }
    }
}

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
