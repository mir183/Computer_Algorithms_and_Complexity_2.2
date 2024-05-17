#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int n, m, startnode;
vector<vector<int>> adj;
vector<bool> vis;
stack<int> st;

void topologicalSortUtil(int v) {
    vis[v] = true;
    for(auto i : adj[v]) {
        if(!vis[i]) {
            topologicalSortUtil(i);
        }
    }
    st.push(v);
}

void topologicalSort() {
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            topologicalSortUtil(i);
        }
    }
    while (!st.empty()) {
        int v = st.top();
        cout << v << " ";
        st.pop();
    }
}

void addedge(int u, int v) {
    adj[u].push_back(v);
}

int main() {
    cout<<"Enter the number of nodes and edges: ";
    cin >> n >> m;
    adj.resize(n);
    vis.resize(n, false);
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        addedge(u, v);
    }
    cout<<"Topological Sort: ";
    topologicalSort();
    return 0;
}