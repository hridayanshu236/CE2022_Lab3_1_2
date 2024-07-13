#include "../include/graph.h"
#include <iostream>

int main() {
    Graph g(true); // Creating a directed graph

    // Adding vertices
    g.addVertex(); // Vertex 0
    g.addVertex(); // Vertex 1
    g.addVertex(); // Vertex 2
    g.addVertex(); // Vertex 3

    // Adding edges
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);

    // Initial state
    std::cout << "Initial state:" << std::endl;
    std::cout << "Number of vertices: " << g.numVertices() << std::endl;
    std::cout << "Number of edges: " << g.numEdges() << std::endl;

    // Neighbours of vertex 1
    std::cout << "Neighbours of vertex 1: ";
    for (int n : g.neighbours(1)) {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    // Check if vertex 2 is a neighbour of vertex 1
    std::cout << "Is vertex 2 a neighbour of vertex 1? " << (g.neighbour(1, 2) ? "Yes" : "No") << std::endl;

    // Removing an edge
    g.removeEdge(1, 2);

    // State after removing edge
    std::cout << "\nAfter removing edge from 1 to 2:" << std::endl;
    std::cout << "Number of vertices: " << g.numVertices() << std::endl;
    std::cout << "Number of edges: " << g.numEdges() << std::endl;

    // Removing a vertex
    g.removeVertex(2);

    // State after removing vertex
    std::cout << "\nAfter removing vertex 2:" << std::endl;
    std::cout << "Number of vertices: " << g.numVertices() << std::endl;
    std::cout << "Number of edges: " << g.numEdges() << std::endl;

    // Check if vertex 3 is still a neighbour of vertex 2 (should be invalid since vertex 2 is removed)
    std::cout << "Is vertex 3 a neighbour of vertex 2? " << (g.neighbour(2, 3) ? "Yes" : "No") << std::endl;

    return 0;
}
