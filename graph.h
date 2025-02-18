#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <cstring>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

const int MAX_NODES = 100;
const int INF = 1000000;

class Graph {
public:
    Graph();
    void addNode(const string& node);
    void addEdge(const string& fromNode, const string& toNode, int distance);
    void removeNode(const string& node);
    void removeEdge(const string& fromNode, const string& toNode);
    int shortestPath(const string& start, const string& end, vector<string>& path);

    void saveToFile(const string& filename);
    void loadFromFile(const string& filename);
    void clearEdges(); // Added function


private:
    string nodes[MAX_NODES];
    int adjacencyMatrix[MAX_NODES][MAX_NODES];
    int nodeCount;

    int getNodeIndex(const string& node);
    int minDistance(int dist[], bool visited[]);
    void printPath(int prev[], int j, std::vector<std::string>& path);



};

#endif // GRAPH_H
