#include <bits/stdc++.h> 

void dfsTS(int node,unordered_map<int, bool> &visited,unordered_map<int, list<int>> &adj, stack<int> &s ){

    visited[node] = 1;

    for(auto i: adj[node]){
        if(!visited[i]){
            dfsTS(i, visited, adj, s);
        }
    }
    s.push(node);
}
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    vector<int> ans;
    unordered_map<int, list<int>> adj;

    for(int i=0; i<edges.size(); i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
    }

    unordered_map<int, bool> visited;
    stack<int> s;

    for(int i=0; i<v; i++){
        if(!visited[i]){
            dfsTS(i, visited, adj, s);
        }
    }

    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }

    return ans;
}