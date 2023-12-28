#include <iostream>
#include "AMGraph.hh"
#include "ALGraph.hh"
int main(){
    ALGraph myGraph;
    myGraph.addVertex("Ramelton");
    myGraph.addVertex("Milford");
    myGraph.addVertex("Letterkenny");
    myGraph.addVertex("Dublin");
    myGraph.addVertex("Munich");
    myGraph.addVertex("Amsterdam");
    myGraph.addVertex("Delft");
    myGraph.addVertex("Kentucky");
    myGraph.addVertex("Wisconsin");

    myGraph.addEdge("Ramelton", "Milford");
    myGraph.addEdge("Ramelton", "Letterkenny");
    myGraph.addEdge("Letterkenny", "Milford");
    myGraph.addEdge("Letterkenny", "Dublin");
    myGraph.addEdge("Delft", "Amsterdam");
    myGraph.addEdge("Munich", "Amsterdam");
    myGraph.addEdge("Munich", "Dublin");
    myGraph.addEdge("Amsterdam", "Dublin");
    myGraph.addEdge("Kentucky", "Wisconsin");
    std::cout << myGraph << std::endl;
    std::cout << "Are Ramelton and Delft connected (bfs): " << myGraph.bfs("Ramelton", "Delft") << std::endl;
    std::cout << "Are Ramelton and Delft connected (dfs): " << myGraph.bfs("Ramelton", "Delft") << std::endl;
    std::cout << std::endl;
    std::cout << "Are Milford and Kentucky connected (bfs): " << myGraph.bfs("Milford", "Kentucky") << std::endl;
    std::cout << "Are Milford and Kentucky connected (dfs): " << myGraph.bfs("Milford", "Kentucky") << std::endl;
    return 0;
}