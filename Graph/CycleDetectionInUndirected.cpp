#include<unordered_map>
#include<queue>
#include<list>

bool isCycleBFS(int src,unordered_map<int, bool> &visited,unordered_map<int, list<int>> &adj ){
    unordered_map<int, int> parent;

    parent[src] = -1;
    visited[src] = true;

    queue<int> q;
    q.push(src);

    while(!q.empty()){
        int front = q.front();
        q.pop();

        for(auto i: adj[front]){
            if(visited[i]==true && i!=parent[front]){
                return true;
            }
            else if(!visited[i]){
                q.push(i);
                parent[i] = front;
                visited[i] = true;
            }
        }
    }

    return false;
}

bool isCycleDFS(int node, int parent,unordered_map<int, bool> &visited,unordered_map<int, list<int>> &adj ){

    visited[node] = 1;

    for(auto i: adj[node]){
        if(!visited[i]){
            bool cycleDetected = isCycleDFS(i, node, visited, adj);
            if(cycleDetected){
                return true;
            }
        }
        else if(i != parent){
            return true;
        }
    }
    return false;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    unordered_map<int, list<int>> adj;
    unordered_map<int, bool> visited;

    for(int i=0; i<edges.size(); i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i=0; i<n; i++){
        if(!visited[i]){
            bool ans = isCycleDFS(i,-1, visited, adj);
            if(ans==true){
                return "Yes";
            }
        }

    }
    return "No";
}
