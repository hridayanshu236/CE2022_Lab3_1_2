#include<iostream>
#include<vector>
#include"graph.h"
Graph::Graph(int numVertices, bool directed){
    this->directed = directed;
    for(int i=0; i<numVertices;i++){
        std::vector<int>row(numVertices,0);
        this->adjMatrix.push_back(row);
    }
}