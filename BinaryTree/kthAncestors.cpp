/*
Link: https://www.geeksforgeeks.org/problems/kth-ancestor-in-a-tree/1
*/

void solve(Node* root, int k, int node, int &ans, vector<int> &temp){
    if(root==NULL){
        return;
    }
    
    if(root->data == node && temp.size()>=k){
        ans = temp[temp.size()-k];
        return;
    }
    
    temp.push_back(root->data);
    solve(root->left, k, node, ans, temp);
    solve(root->right, k, node, ans, temp);
    temp.pop_back();
}
int kthAncestor(Node *root, int k, int node)
{
    int ans = -1;
    vector<int> temp;
    solve(root, k, node, ans, temp);
    return ans;
}

