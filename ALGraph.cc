#include <string>
#include <vector>
#include <unordered_map>
#include <stack>
#include <queue>

#include "ALGraph.hh"
void ALGraph::addVertex(std::string vertex){
    if (vertexMap.find(vertex) != vertexMap.end()) {}
    else {
        std::cout << "Adding vertex " << vertex <<  " with index " << vertexCount << std::endl;
        adjList.push_back(std::vector<int> ());
        vertexMap.insert(std::pair<std::string, int> (vertex, vertexCount));
        indexMap.insert(std::pair<int, std::string> (vertexCount, vertex));
        ++vertexCount;
    }
}

void ALGraph::addEdge(std::string v1, std::string v2){
    auto p1 = vertexMap.find(v1);
    auto p2 = vertexMap.find(v2);
    if (p1 == vertexMap.end() || p2 == vertexMap.end()){}
    else {
        int ind1 = p1 -> second; 
        int ind2 = p2 -> second; 
        adjList[ind1].push_back(ind2);
        adjList[ind2].push_back(ind1);
        std::cout << "Adding edge between " << v1 << "(" << ind1 << ") and " << v2 << "(" << ind2 << ")" << std::endl;

    }
}

std::ostream& operator<<(std::ostream& os, const ALGraph g){
    for (int i=0; i<g.vertexCount; ++i){
        os << std::setw(12) << (g.indexMap).at(i) << ":";
        int listLen = (g.adjList[i]).size();
        for (int j=0; j<listLen; ++j){
            os << std::setw(4) << g.adjList[i][j];
        }
        std::cout << std::endl;
    }
    return os;
}
std::vector<int> ALGraph::findConnections(std::string vertex){
    auto p1 = vertexMap.find(vertex);
    if (p1 == vertexMap.end()) {}
    else {
        int ind = p1 -> second;
        return adjList[ind];
    }
    return std::vector<int> ();
}

std::vector<std::string> ALGraph::showConnections (std::string vertex) {
    std::vector<std::string> connections;
    auto p1 = vertexMap.find(vertex);
    if (p1 == vertexMap.end()){}
    else {
        int ind = p1 -> second;
        int numConnections = adjList[ind].size();
        for (int i=0; i<numConnections; ++i){
            int cIndex = adjList[ind][i];
            std::string connection = indexMap.at(cIndex);
            connections.push_back(connection);
        }
    }
    return connections;
}

bool ALGraph::bfs(std::string v1, std::string v2){
    auto p1 = vertexMap.find(v1);
    auto p2 = vertexMap.find(v2);
    if (p1 == vertexMap.end() || p2 == vertexMap.end())
        return false;
    else{
        int source = p1 -> second;
        int target = p2 -> second;
        std::queue<int> toVisit;
        std::vector<int> visited(vertexCount, false);
        toVisit.push(source);
        visited[source] = 1;
        while(!toVisit.empty()){
            int current = toVisit.front();
            toVisit.pop();
            for (int i : adjList[current]){
                if (i == target)
                    return true;
                else if (visited[i] == 1) {}
                else{
                    toVisit.push(i);
                    visited[i] = 1;
                }
            }
            
        }
    }
    return false;
}

bool ALGraph::dfs(std::string v1, std::string v2){
    auto p1 = vertexMap.find(v1);
    auto p2 = vertexMap.find(v2);
    if (p1 == vertexMap.end() || p2 == vertexMap.end())
        return false;
    else{
        int source = p1 -> second;
        int target = p2 -> second;
        std::stack<int> toVisit;
        std::vector<int> visited(vertexCount, false);
        toVisit.push(source);
        visited[source] = 1;
        while(!toVisit.empty()){
            int current = toVisit.top();
            toVisit.pop();
            for (int i : adjList[current]){
                if (i == target)
                    return true;
                else if (visited[i] == 1) {}
                else{
                    toVisit.push(i);
                    visited[i] = 1;
                }
            }
            
        }
    }
    return false;
}
