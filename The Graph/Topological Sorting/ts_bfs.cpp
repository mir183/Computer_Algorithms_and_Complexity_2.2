#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
vector<vector<int>> adj;
vector<int> indegree;
queue<int> q;

void topologicalSort() {
    for(int i = 0; i < n; i++) {
        if(indegree[i] == 0) {
            q.push(i);
        }
    }
    while(!q.empty()) {
        int v = q.front();
        q.pop();
        cout << v << " ";
        for(auto i : adj[v]) {
            indegree[i]--;
            if(indegree[i] == 0) {
                q.push(i);
            }
        }
    }
}

void addedge(int u, int v) {
    adj[u].push_back(v);
    indegree[v]++;
}

int main() {
    cout<<"Enter the number of nodes and edges: ";
    cin >> n >> m;
    adj.resize(n);
    indegree.resize(n, 0);
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        addedge(u, v);
    }
    cout<<"Topological Sort: ";
    topologicalSort();
    return 0;
}