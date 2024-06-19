#include<vector>

class Graph{
    private:
        bool directed;
        std::vector<std::vector<int>> adjMatrix;
    public:
        Graph(int numVertices, bool directed=true);
        
};