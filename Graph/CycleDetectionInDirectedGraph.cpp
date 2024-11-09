#include<unordered_map>
#include<list>
#include<queue>

bool checkCycleDFS(int node,unordered_map<int, bool> &visited,unordered_map<int, bool> &dfsVis, unordered_map<int, list<int>>adj){

  visited[node]=true;
  dfsVis[node] = true;

  for(auto i: adj[node]){
    if(!visited[i]){
      bool cycleDetected = checkCycleDFS(i, visited,dfsVis,adj);
      if(cycleDetected)
        return true;
    }
    else if(dfsVis[i]){
      return true;
    }
  }

  dfsVis[node] = false;
  return false;
}


int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  unordered_map<int, list<int>>adj;

  for(int i=0; i<edges.size(); i++){
    int u = edges[i].first;
    int v = edges[i].second;

    adj[u].push_back(v);
  }

  unordered_map<int, bool> visited;
  unordered_map<int, bool> dfsVis;

  for(int i=1; i<=n; i++){
    if(!visited[i]){
      bool ans = checkCycleDFS(i, visited, dfsVis, adj);
      if(ans){
        return 1;
      }
    }
  }
  return 0;
}