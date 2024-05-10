#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, m, startnode;
vector<vector<int>> adj;
vector<bool> vis;

void bfs(int s) {
    queue<int> q;
    vis[s] = true;
    q.push(s);
    while (!q.empty()) {
        int cn = q.front();
        q.pop();
        cout << cn << " ";
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

    return 0;
}