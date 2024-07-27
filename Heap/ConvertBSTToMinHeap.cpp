#include<iostream>

using namespace std;

void inOrderTraversal(Node* root, vector<int> &in){
    //base case

    if(root==NULL){
        return;
    }

    inOrderTraversal(root->left, in);
    in.push_back(root->data);
    inOrderTraversal(root->right,in);
}

void buildByPreOrder(Node* root, vector<int> &in,int index){
    //base case

    if(root==NULL){
        return;
    }

    root->data = in[index++];
    buildByPreOrder(root->left,in, index);
    buildByPreOrder(root->right,in, index);
}
Node* convertBSTtoMinHeap(Node* root){


    vector<int> inOrder;
    inOrderTraversal(root, inOrder);
    int index = 0;
    buildByPreOrder(root, inOrder,index);
}