#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<vector<int>> &adj, int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u); // undirected
}

void BFS(const vector<vector<int>> &adj, int s) {
    int V = adj.size();
    vector<bool> visited(V, false);
    queue<int> q;
    visited[s] = true;
    q.push(s);
    cout << "BFS: ";
    while (!q.empty()) {
        int u = q.front(); q.pop();
        cout << u << " ";
        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
    cout << endl;
}

void DFSUtil(const vector<vector<int>> &adj, int u, vector<bool> &visited) {
    visited[u] = true;
    cout << u << " ";
    for (int v : adj[u])
        if (!visited[v]) DFSUtil(adj, v, visited);
}

void DFS(const vector<vector<int>> &adj, int s) {
    int V = adj.size();
    vector<bool> visited(V, false);
    cout << "DFS: ";
    DFSUtil(adj, s, visited);
    cout << endl;
}

int main() {
    int V = 5;
    vector<vector<int>> adj(V);
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);

    BFS(adj, 0);
    DFS(adj, 0);
    return 0;
}
