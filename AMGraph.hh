#ifndef AMGRAPH_HH_
#define AMGRAPH_HH_
#include <iostream>
#include <map>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <iterator>
#include <queue>
// Class definition for Adjacency Matrix Graph
class AMGraph{
public:
    AMGraph() : vertexCounter {0} {}
    void addVertex(std::string vertex);
    void addEdge(std::string v1, std::string v2);
    friend std::ostream& operator<<(std::ostream& os, const AMGraph g);
    bool directlyConnected(std::string v1, std::string v2);
    std::vector<int> findConnections(int initial);
    std::vector<std::string> listConnections(std::string vertex);
    bool bfs(std::string v1, std::string v2);
    bool dfs(std::string v1, std::string v2);
    
private:
    std::vector<std::vector<int>> aMatrix;
    std::map<std::string, int> vertexMap;
    std::map<int, std::string> indexMap;
    int vertexCounter;
};
#endif