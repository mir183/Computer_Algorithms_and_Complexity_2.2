#include <iostream>
#include <limits.h>
#include <vector>
#include <queue>
using namespace std;

#define INF INT_MAX

vector<vector<pair<int, int>>> graph;
vector<int> dist;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

void dijkstra(int start) {
    int n = graph.size();
    dist.assign(n, INF);

    dist[start] = 0;
    pq.push(make_pair(0, start));

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (auto x : graph[u]) {
            int v = x.first;
            int weight = x.second;

            if (dist[v] > dist[u] + weight) {
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
            }
        }
    }
}

void addedge(int u, int v, int w) {
    graph[u].push_back({v, w});
    graph[v].push_back({u, w}); // Remove this line if the graph is directed
}

// Use this main function if your nodes are 0-indexed
int main() {
    int n, m;
    cout << "Enter the number of nodes: ";
    cin >> n;
    cout << "Enter the number of edges: ";
    cin >> m;

    graph.resize(n);

    cout << "Enter the edges (node1 node2 weight):" << endl;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        addedge(u, v, w);
    }

    // Run Dijkstra's algorithm
    int startnode;
    cout << "Enter the starting node: ";
    cin >> startnode;
    dijkstra(startnode);

    // Print the shortest distances to all nodes from the starting node
    for (int i = 0; i < dist.size(); i++) {
        cout << "Distance from node " << startnode << " to node " << i << " is " << dist[i] << endl;
    }

    return 0;
}

// Use this main function if your nodes are 1-indexed
/*
int main() {
    int n, m;
    cout << "Enter the number of nodes: ";
    cin >> n;
    cout << "Enter the number of edges: ";
    cin >> m;

    graph.resize(n);

    cout << "Enter the edges (node1 node2 weight):" << endl;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        // Subtract 1 if your nodes are 1-indexed
        addedge(u - 1, v - 1, w);
    }

    // Run Dijkstra's algorithm
    int startnode;
    cout << "Enter the starting node: ";
    cin >> startnode;
    // Subtract 1 if your nodes are 1-indexed
    startnode -= 1;

    // Check if the starting node is valid
    if (startnode < 0 || startnode >= n) {
        cout << "Invalid starting node." << endl;
        return 1;
    }

    dijkstra(startnode);

    // Print the shortest distances to all nodes from the starting node
    for (int i = 0; i < dist.size(); i++) {
        cout << "Distance from node " << startnode + 1 << " to node " << i + 1 << " is " << dist[i] << endl;
    }

    return 0;
}
*/