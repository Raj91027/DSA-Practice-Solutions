
/*
https://www.geeksforgeeks.org/problems/interleave-the-first-half-of-the-queue-with-second-half/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article
*/










//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    vector<int> rearrangeQueue(queue<int> &q){
        stack<int> s;
        vector<int> ans;
        
        int n = q.size()/2;
        
        while(n > 0){
            s.push(q.front());
            q.pop();
            n--;
        }
        
        while(!s.empty()){
            q.push(s.top());
            s.pop();
        }
        
        n = q.size()/2;
        
        while(n > 0){
            q.push(q.front());
            q.pop();
            n--;
        }
        
        n = q.size()/2;
        
        while(n > 0){
            s.push(q.front());
            q.pop();
            n--;
        }
        
         while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
            
            ans.push_back(q.front());
            q.pop();
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        queue<int> q;
        for(int i=0;i<n;i++){
            int a;
            cin>>a;
            q.push(a);
        }
        Solution ob;
        vector<int> ans=ob.rearrangeQueue(q);
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}
// } Driver Code Ends