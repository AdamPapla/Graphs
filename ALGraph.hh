#ifndef ALGRAPH_HH_
#define ALGRAPH_HH_
#include <iostream>
#include <map>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <iterator>
#include <unordered_map>

class ALGraph{
public:
    ALGraph() : vertexCount {0} {
        for (auto v : adjList){
            for (int i : v)
                std::cout << i << ", ";
            std::cout << std::endl;
        }
    } 
    void addVertex(std::string vertex);
    void addEdge(std::string v1, std::string v2);
    std::vector<int> findConnections(std::string vertex);
    friend std::ostream& operator<<(std::ostream& os, const ALGraph g);
    bool bfs(std::string v1, std::string v2);
    bool dfs(std::string v1, std::string v2);
private: 
    int vertexCount;
    std::unordered_map<std::string, int> vertexMap;
    std::unordered_map<int, std::string> indexMap;
    std::vector<std::vector<int>> adjList;
};

#endif