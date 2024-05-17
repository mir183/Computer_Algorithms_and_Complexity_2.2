#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, startnode;
vector<vector<int>> adj;
vector<bool> vis;
vector<int> path;

void bfs(int s) {
    queue<int> q;
    vis[s] = true;
    q.push(s);
    while (!q.empty()) {
        int cn = q.front();
        q.pop();
        path.push_back(cn);
        for(auto i : adj[cn]) {
            if(!vis[i]) {
                vis[i] = true;
                q.push(i);
            }
        }
    }
}

void addedge(int u, int v) {
    adj[u].push_back(v);
}

signed main() {
    cout << "Enter the number of nodes and edges: ";
    cin >> n >> m;
    adj.resize(n+1);
    vis.resize(n+1, false);

    for(auto i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        addedge(u, v);
    }

    cout << "Enter the starting node: ";
    cin >> startnode;
    bfs(startnode);
    cout << "BFS: ";
    for(auto i : path) {
        cout << i << " ";
    }
    cout << endl;
    reverse(path.begin(), path.end());
    cout << "Backtrack: ";
    for(auto i : path) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}