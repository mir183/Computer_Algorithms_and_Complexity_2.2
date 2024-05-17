#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, startnode;
vector<vector<int>> adj;
vector<bool> vis;
vector<int> path;

void dfs(int s) {
    stack<int> st;
    vis[s] = true;
    st.push(s);
    while (!st.empty()) {
        int cn = st.top();
        st.pop();
        path.push_back(cn);
        for(auto i : adj[cn]) {
            if(!vis[i]) {
                vis[i] = true;
                st.push(i);
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
    dfs(startnode);
    cout<<"DFS: ";
    for(auto i : path) {
        cout << i << " ";
    }
    cout << endl;
    reverse(path.begin(), path.end());
    cout<<"Backtrack: ";
    for(auto i : path) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}