#include<unordered_map>
#include<queue>

vector<int> bfsTraversal(int n, vector<vector<int>> &adj){
    unordered_map<int ,bool> visited;
    vector<int> ans;
   
    queue<int> q;
    q.push(0);
    visited[0] = true;
    while(!q.empty()){
        int frontNode = q.front();
        q.pop();
        ans.push_back(frontNode);

        for(auto i:adj[frontNode]){
            if(!visited[i]){
                q.push(i);
                visited[i] = true;
            }
        }
    } 
    return ans;
}