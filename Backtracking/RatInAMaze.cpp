#include <bits/stdc++.h> 
bool isSafe(int newx, int newy, vector<vector<bool>> &vis,vector < vector < int >> & arr, int n ){
    if((newx >=0 && newx < n) &&(newy >=0 && newy < n)
        &&(vis[newx][newy]!=1) &&(arr[newx][newy]==1)){
            return true;
        }
        else{
            return false;
        }
}

void solve(int x, int y, vector < vector < int >> & arr,int n, vector<vector<bool>> &vis,vector<string> &ans,
             string path){

                //base case
                if(x == n-1 && y==n-1){
                    ans.push_back(path);
                    return;
                }

                //four movement
                //D, L, R, U

                //Down 
                vis[x][y] = 1;
                if(isSafe(x+1, y, vis, arr, n)){
                    solve(x+1,y,arr, n,vis, ans,path +'D');
                }

                //Left
                if(isSafe(x, y-1, vis, arr, n)){
                    solve(x,y-1, arr, n,vis,ans,path +'L');
                }

                //Right
                if(isSafe(x, y+1, vis, arr, n)){
                    solve(x,y+1, arr, n, vis,ans,path +'R');
                }

                //Up
                if(isSafe(x-1, y, vis, arr, n)){
                    solve(x-1,y, arr, n, vis,ans,path +'U');
                }

                vis[x][y] = 0;
            }

vector < string > searchMaze(vector < vector < int >> & arr, int n) {
    vector<string> ans;
    vector<vector<bool>> visited(n, vector<bool>(n,0));
    string path="";

    if(arr[0][0]==0){
        return ans;
    }

    solve(0,0,arr,n,visited,ans,path);
    return ans;
}