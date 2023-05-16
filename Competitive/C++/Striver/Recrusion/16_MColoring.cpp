#include<bits/stdc++.h>

using namespace std;
bool check (int col, vector<int>& color, int node, vector<int>& edges) {
    for (int i : edges) {
        if (color[i] == col) return false;
    }
    return true;
}
bool Mcoloring(int node, int n, int m, vector<int>& color, vector<vector<int>>& graph) {
    if (node == n) return true;

    for (int col=1; col<=m; col++) {
        if (check(col, color, node, graph[node])) {
            color[node] = col;
            if (Mcoloring(node+1, n, m, color, graph)) return true;
            color[node] = 0;
        }
    }

    return false;
}


int main() {
    int n,m,e; cin >> n >> m >> e;
    vector<vector<int>> graph(n+1);
    for (int i=0; i<e; i++) {
        int u,v; cin >> u >> v;
        graph[u].push_back(v),
        graph[v].push_back(u);
    }
    vector<int> color(n+1,0);
    
    cout << Mcoloring(1,n,m,color,graph);
}