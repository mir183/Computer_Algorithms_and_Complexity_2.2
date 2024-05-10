#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int n, m, startnode;
vector<vector<int>> adj;
vector<bool> vis;

void dfs(int s) {
    stack<int> st;
    vis[s] = true;
    st.push(s);
    while (!st.empty()) {
        int cn = st.top();
        st.pop();
        cout << cn << " ";
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

    return 0;
}