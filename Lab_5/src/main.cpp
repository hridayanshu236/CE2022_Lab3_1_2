#include "../include/graph.h"
#include <iostream>

int main() {
    Graph g(true);

    g.addVertex();
    g.addVertex();
    g.addVertex();

    g.addEdge(0, 1);
    g.addEdge(1, 2);

    std::cout << "Is graph empty? " << (g.isEmpty() ? "Yes" : "No") << std::endl;
    std::cout << "Is graph directed? " << (g.isDirected() ? "Yes" : "No") << std::endl;
    std::cout << "Number of vertices: " << g.numVertices() << std::endl;
    std::cout << "Number of edges: " << g.numEdges() << std::endl;
    std::cout << "Indegree of vertex 1: " << g.indegree(1) << std::endl;
    std::cout << "Outdegree of vertex 1: " << g.outdegree(1) << std::endl;
    std::cout << "Degree of vertex 1: " << g.degree(1) << std::endl;
    std::cout << "Neighbours of vertex 1: ";
    for (int n : g.neighbours(1)) {
        std::cout << n << " ";
    }
    std::cout << std::endl;
    std::cout << "Is vertex 2 a neighbour of vertex 1? " << (g.neighbour(1, 2) ? "Yes" : "No") << std::endl;

    return 0;
}