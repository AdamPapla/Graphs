#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include "graph.hh"

void AMGraph::addVertex(std::string vertex){
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
void AMGraph::addEdge(std::string v1, std::string v2){
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

std::ostream& operator<<(std::ostream& os, const AMGraph g){
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
bool AMGraph::directlyConnected(std::string v1, std::string v2){
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

std::vector<int> AMGraph::findConnections(int initial){
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
std::vector<std::string> AMGraph::listConnections(std::string vertex){
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
bool AMGraph::bfs(std::string v1, std::string v2){
    // Breadth first search algorithm
    std::queue<int> toVisit;
    auto pStart = vertexMap.find(v1);
    auto pEnd = vertexMap.find(v2);
    if (pStart == vertexMap.end() || pEnd == vertexMap.end()){
        return false;
    }
    int start = pStart -> second;
    int target = pEnd -> second;
    toVisit.push(start);
    std::vector<bool> visited (vertexCounter, false);
    visited[start] = true;
    while(!toVisit.empty()){
        int root = toVisit.front();
        toVisit.pop();
        std::vector<int> connections = findConnections(root);
        for (int i : connections){
            if (i == target){
                return true;
            }
            else if (visited[i] == 1) {}
            else {
                toVisit.push(i);
                visited[i] = 1;
            }
        }
    }
    return false;
}
bool AMGraph::dfs(std::string v1, std::string v2){
    auto p1 = vertexMap.find(v1);
    auto p2 = vertexMap.find(v2);
    if (p1 == vertexMap.end() || p2 == vertexMap.end()) {}
    else{
        std::stack<int> toVisit;
        int source = p1 -> second;
        int dest = p2 -> second;
        toVisit.push(source);
        std::vector<bool> visited (vertexCounter, false);
        visited[source] = true;
        while (!toVisit.empty()){
            int root = toVisit.top();
            toVisit.pop();
            std::vector<int> connections = findConnections(root);
            for (int i : connections){
                if (i == dest)
                    return true;
                else if (visited[i] == true) {}
                else {
                    toVisit.push(i);
                    visited[i] = 1;
                }
            }
        }
    }
    return false;
}