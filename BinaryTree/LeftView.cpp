/*
 https://www.geeksforgeeks.org/problems/left-view-of-binary-tree/1
 */



void solve(Node* root, vector<int> & ans, int level){
    if(root==NULL)
        return;
        
    if(level==ans.size())
        ans.push_back(root->data);
    
    solve(root->left, ans, level+1);
    solve(root->right, ans, level+1);
        
}
//Function to return a list containing elements of left view of the binary tree.
vector<int> leftView(Node *root)
{
    vector<int> ans;
    int level = 0;
      
    if(root==NULL)
        return ans;
    
    solve(root, ans, level);
    
    return ans;
}