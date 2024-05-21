#include <iostream>
#include <limits.h>
#include <vector>
using namespace std;

#define INF INT_MAX

struct Edge {
    int u, v, w;
};

vector<Edge> edges;
vector<int> dist;

void bellmanFord(int start, int n) {
    dist.assign(n, INF);
    dist[start] = 0;

    for (int i = 0; i < n - 1; i++) {
        for (Edge &e : edges) {
            if (dist[e.u] != INF && dist[e.v] > dist[e.u] + e.w) {
                dist[e.v] = dist[e.u] + e.w;
            }
        }
    }

    // Check for negative weight cycles
    for (Edge &e : edges) {
        if (dist[e.u] != INF && dist[e.v] > dist[e.u] + e.w) {
            cout << "Graph contains a negative-weight cycle" << endl;
            return;
        }
    }
}

void addedge(int u, int v, int w) {
    edges.push_back({u, v, w});
    edges.push_back({v, u, w}); //comment this line for undirected graph
}

// use this main function for 0 based indexing
int main() {
    int n, m;
    cout << "Enter the number of nodes: ";
    cin >> n;
    cout << "Enter the number of edges: ";
    cin >> m;

    cout << "Enter the edges (node1 node2 weight):" << endl;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        addedge(u, v, w);
    }

    // Run Bellman-Ford algorithm
    int startnode;
    cout << "Enter the starting node: ";
    cin >> startnode;
    bellmanFord(startnode, n);

    // Print the shortest distances to all nodes from the starting node
    for (int i = 0; i < dist.size(); i++) {
        cout << "Distance from node " << startnode << " to node " << i << " is " << dist[i] << endl;
    }

    return 0;
}

// use this main function for 1 based indexing
/*
int main() {
    int n, m;
    cout << "Enter the number of nodes: ";
    cin >> n;
    cout << "Enter the number of edges: ";
    cin >> m;

    cout << "Enter the edges (node1 node2 weight):" << endl;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        // Subtract 1 from the nodes here
        addedge(u - 1, v - 1, w);
    }

    // Run Bellman-Ford algorithm
    int startnode;
    cout << "Enter the starting node: ";
    cin >> startnode;
    // Subtract 1 from the starting node here
    bellmanFord(startnode - 1, n);

    // Print the shortest distances to all nodes from the starting node
    for (int i = 0; i < dist.size(); i++) {
        // Add 1 to the nodes here
        cout << "Distance from node " << startnode << " to node " << i + 1 << " is " << dist[i] << endl;
    }

    return 0;
}
*/