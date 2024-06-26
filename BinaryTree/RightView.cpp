/*
Link: https://www.geeksforgeeks.org/problems/right-view-of-binary-tree/1
*/


class Solution
{
    public:
    void solve(Node* root, vector<int> & ans, int level){
        if(root==NULL)
            return;
        
        if(level==ans.size())
            ans.push_back(root->data);
            
        solve(root->right, ans, level+1);
        solve(root->left, ans, level+1);
        
    }
    //Function to return list containing elements of right view of binary tree.
    vector<int> rightView(Node *root)
    {
       vector<int> ans;
        int level = 0;
          
        if(root==NULL)
            return ans;
        
        solve(root, ans, level);
        
        return ans;
    }
};