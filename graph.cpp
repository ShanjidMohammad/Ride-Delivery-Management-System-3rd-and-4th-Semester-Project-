#include "graph.h"

Graph::Graph() {
    nodeCount = 0;
    memset(adjacencyMatrix, -1, sizeof(adjacencyMatrix));
}

void Graph::addNode(const string& node) {
    if (nodeCount < MAX_NODES) {
        nodes[nodeCount] = node;
        nodeCount++;
    } else {
        cerr << "Error: Maximum node limit reached." << endl;
    }
}

void Graph::addEdge(const string& fromNode, const string& toNode, int distance) {
    int fromIndex = getNodeIndex(fromNode);
    int toIndex = getNodeIndex(toNode);
    if (fromIndex != -1 && toIndex != -1) {
        adjacencyMatrix[fromIndex][toIndex] = distance;
        adjacencyMatrix[toIndex][fromIndex] = distance;
    } else {
        cerr << "Error: One or both nodes not found." << endl;
    }
}

void Graph::removeNode(const string& node) {
    int index = getNodeIndex(node);
    if (index != -1) {
        for (int i = 0; i < nodeCount; ++i) {
            adjacencyMatrix[i][index] = -1;
            adjacencyMatrix[index][i] = -1;
        }
        nodes[index] = nodes[nodeCount - 1];
        nodeCount--;
    } else {
        cerr << "Error: Node not found." << endl;
    }
}

void Graph::removeEdge(const string& fromNode, const string& toNode) {
    int fromIndex = getNodeIndex(fromNode);
    int toIndex = getNodeIndex(toNode);
    if (fromIndex != -1 && toIndex != -1) {
        adjacencyMatrix[fromIndex][toIndex] = -1;
        adjacencyMatrix[toIndex][fromIndex] = -1;
    } else {
        cerr << "Error: One or both nodes not found." << endl;
    }
}

int Graph::shortestPath(const string& start, const string& end, vector<string>& path) {
    int startIdx = getNodeIndex(start);
    int endIdx = getNodeIndex(end);

    if (startIdx == -1 || endIdx == -1) {
        cerr << "Error: Start or end node not found." << endl;
        return INF; // Return a large value to indicate an error
    }

    int dist[MAX_NODES], prev[MAX_NODES];
    bool visited[MAX_NODES];
    for (int i = 0; i < MAX_NODES; ++i) {
        dist[i] = INF;
        prev[i] = -1;
        visited[i] = false;
    }

    dist[startIdx] = 0;

    for (int i = 0; i < nodeCount; ++i) {
        int u = minDistance(dist, visited);
        if (u == -1) break;
        visited[u] = true;

        for (int v = 0; v < nodeCount; ++v) {
            if (!visited[v] && adjacencyMatrix[u][v] != -1 && dist[u] != INF &&
                dist[u] + adjacencyMatrix[u][v] < dist[v]) {
                dist[v] = dist[u] + adjacencyMatrix[u][v];
                prev[v] = u;
            }
        }
    }

    path.clear(); // Clear the vector before populating
    if (dist[endIdx] == INF) {
        path.push_back("No path found from '" + start + "' to '" + end + "'.");
        return INF; // Return a large value to indicate no path found
    } else {
        printPath(prev, endIdx, path);
        return dist[endIdx]; // Return the total distance
    }
}


void Graph::saveToFile(const string& filename) {
    ofstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: Could not open file for writing." << endl;
        return;
    }

    file << nodeCount << endl;
    for (int i = 0; i < nodeCount; ++i) {
        file << nodes[i] << endl;
    }

    for (int i = 0; i < nodeCount; ++i) {
        for (int j = 0; j < nodeCount; ++j) {
            if (adjacencyMatrix[i][j] != -1) {
                file << nodes[i] << " " << nodes[j] << " " << adjacencyMatrix[i][j] << endl;
            }
        }
    }

    file.close();
    cout << "Graph saved to file '" << filename << "' successfully." << endl;
}

void Graph::loadFromFile(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: Could not open file for reading." << endl;
        return;
    }

    file >> nodeCount;
    for (int i = 0; i < nodeCount; ++i) {
        file >> nodes[i];
    }

    memset(adjacencyMatrix, -1, sizeof(adjacencyMatrix));

    string fromNode, toNode;
    int distance;
    while (file >> fromNode >> toNode >> distance) {
        addEdge(fromNode, toNode, distance);
    }

    file.close();
    cout << "Graph loaded from file '" << filename << "' successfully." << endl;
}

void Graph::clearEdges() {
    memset(adjacencyMatrix, -1, sizeof(adjacencyMatrix));
}

int Graph::getNodeIndex(const string& node) {
    for (int i = 0; i < nodeCount; ++i) {
        if (nodes[i] == node) {
            return i;
        }
    }
    return -1;
}

int Graph::minDistance(int dist[], bool visited[]) {
    int min = INF, min_index = -1;
    for (int i = 0; i < nodeCount; ++i) {
        if (!visited[i] && dist[i] <= min) {
            min = dist[i];
            min_index = i;
        }
    }
    return min_index;
}

void Graph::printPath(int prev[], int j, std::vector<std::string>& path) {
    if (prev[j] == -1) {
        path.push_back(nodes[j]);
        return;
    }
    printPath(prev, prev[j], path);
    path.push_back(nodes[j]);
}



