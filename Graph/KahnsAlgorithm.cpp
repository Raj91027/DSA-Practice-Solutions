#include <bits/stdc++.h> 


vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    vector<int> ans;
    unordered_map<int, list<int>> adj;

//step-1 prepare adjacency list
    for(int i=0; i<edges.size(); i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
    }
//step-2 create indegree vector 
    vector<int> indegree(v);
//step-3 calculate and store indgree
    for(auto i: adj){
        for(auto j: i.second)
            indegree[j]++;
    }

//step-4 make a queue and push all vertices having indegree 0
    queue<int> q;

    for(int i=0;i<v; i++){
        if(indegree[i]==0)
            q.push(i);
    }
//step-5  do bfs
    while(!q.empty()){
        int front = q.front();
        q.pop();
        ans.push_back(front);

        for(auto i: adj[front]){
            //decrease indegree by 1
            indegree[i]--;
            //if indegree is 0 push into queue
            if(indegree[i]==0)
                q.push(i);
        }
    }
// step-6 return ans;
    return ans;
}