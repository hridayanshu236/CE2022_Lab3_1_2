#include <vector>

class Graph {
private:
    std::vector<std::vector<int>> adjMatrix;
    int vertexCount;
    int edgeCount;
    bool directed;

public:
    Graph(bool isDirected = false);
    bool isEmpty() const;
    bool isDirected() const;
    void addVertex();
    void addEdge(int vertex1, int vertex2);
    void removeVertex(int vertex);
    void removeEdge(int vertex1, int vertex2);
    int numVertices() const;
    int numEdges() const;
    int indegree(int vertex) const;
    int outdegree(int vertex) const;
    int degree(int vertex) const;
    std::vector<int> neighbours(int vertex) const;
    bool neighbour(int vertex1, int vertex2) const;
};
