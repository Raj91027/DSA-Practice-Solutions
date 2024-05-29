/*
https://www.geeksforgeeks.org/problems/k-sum-paths/1
*/



class Solution{
  public:
    void solve(Node* root, int k, int &count, vector<int> path){
        //base case
        if(root==NULL)
            return;
        
        path.push_back(root->data);
        
        solve(root->left, k, count, path);
        solve(root->right, k, count, path);
        
        int n = path.size();
        int sum =0;
        for(int i= n-1; i>=0; i--){
            sum+=path[i];
            if(sum==k){
                count++;
            }
        }
        path.pop_back();
    }
    int sumK(Node *root,int k)
    {
        vector<int> path;
        int count=0;
        
        solve(root, k, count, path);
        return count;
    }
};