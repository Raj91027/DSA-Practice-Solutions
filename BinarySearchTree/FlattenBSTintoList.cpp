#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
void inOrderTraversal(TreeNode<int>* root, vector<TreeNode<int>*> &in){
    if(root==NULL)
        return;

    inOrderTraversal(root->left,in);
    in.push_back(root);
    inOrderTraversal(root->right,in);
}

TreeNode<int>* flatten(TreeNode<int>* root)
{
    vector<TreeNode<int>*> inOrder;
    inOrderTraversal(root,inOrder);
    TreeNode<int>* treeNode = inOrder[0];
    TreeNode<int>* curr = treeNode;

    for(int i=1; i<inOrder.size(); i++){
        TreeNode<int>* temp = inOrder[i];
        curr->left = NULL;
        curr->right = temp;
        curr = temp;
    }
    curr->left=NULL;
    curr->right=NULL;

    return treeNode;
    
}
