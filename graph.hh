#ifndef GRAPH_HH_
#define GRAPH_HH_
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
    void addVertex(std::string vertex){
        if (vertexMap.find(vertex) != vertexMap.end()){}
        else{
            vertexMap.insert(std::pair (vertex, vertexCounter));
            indexMap.insert(std::pair (vertexCounter, vertex));
            ++vertexCounter;
            for (std::vector<int>& v : aMatrix)
                v.push_back(0);
            std::vector<int> newRow (vertexCounter, 0);
            aMatrix.push_back(newRow);
            aMatrix[vertexCounter-1][vertexCounter-1] = 1;
        }
    }
    virtual void addEdge(std::string v1, std::string v2){
        auto itV1 = vertexMap.find(v1);
        auto itV2 = vertexMap.find(v2);
        if (itV1 == vertexMap.end() || itV2 == vertexMap.end()) {}
        else{
            int entryV1 = itV1 -> second;
            int entryV2 = itV2 -> second;
            aMatrix[entryV1][entryV2] = 1;
            aMatrix[entryV2][entryV1] = 1;  // Undirected by default
        }
    }
    friend std::ostream& operator<<(std::ostream& os, const AMGraph g){
        os << std::setw(12) << " ";
        for (int i=0; i<g.vertexCounter; ++i){
            os << std::setw(12) << (g.indexMap).at(i);
        }
        os << std::endl;
        for (int i=0; i<g.vertexCounter; ++i){
            os << std::setw(12) << g.indexMap.at(i);
            for (int j=0; j<g.vertexCounter; ++j){
                os << std::setw(12) << g.aMatrix[i][j];
            }
            std::cout << std::endl;
        }
        return os;
    }
    bool areConnected(std::string v1, std::string v2){
        auto p1 = vertexMap.find(v1);
        auto p2 = vertexMap.find(v2);
        if (p1 == vertexMap.end() || p2 == vertexMap.end()){
            return false;
        }
        else{
            int ind1 = p1 -> second;
            int ind2 = p2 -> second;
            return aMatrix[ind1][ind2];
        }
        return false;
    }
    std::vector<int> findConnections(int initial){
        std::vector<int> connections;
        if (initial<0 || initial > vertexCounter){}
        else{
            for (int i=0; i<vertexCounter; ++i){
                if (aMatrix[initial][i] == 1)
                    connections.push_back(i);
            }
        }
        return connections;
    }
    std::vector<std::string> listConnected(std::string vertex){
        std::vector<std::string> connections;
        auto p = vertexMap.find(vertex);
        if (p == vertexMap.end()) {}
        else{
            int ind = p -> second;
            std::vector<int> connectedIndices = findConnections(ind);
            for (int i : connectedIndices)
                connections.push_back(indexMap[i]);

        }
        return connections;
    }
    bool bfs(std::string v1, std::string v2);
    bool dfs(std::string v1, std::string v2);
private:
    std::vector<std::vector<int>> aMatrix;
    std::map<std::string, int> vertexMap;
    std::map<int, std::string> indexMap;
    int vertexCounter;
};
#endif