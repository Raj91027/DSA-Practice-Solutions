/*
Tree Traversal Techniques
    1. Inorder(LNR)
    2. PreOrder(NLR)
    3. PostOrder(LRN)
    4. LevelOrderTraversal(BFS)
*/

#include<iostream>
#include<queue>

using namespace std;

class Node{

    public:
    int data;
    Node* left;
    Node* right;

    Node(int d){
        this->data = d;
        this->left = NULL;
        this->right =NULL;
    }
};

Node* buildTree(Node* root){
    cout<<"Enter data:"<<" ";
    int data;
    cin >> data;

    root = new Node(data);
    if(data==-1){
        return NULL;
    }

    cout<<"Enter data for inserting left of "<< data<<endl;
    root->left = buildTree(root->left);

    cout<<"Enter data for inserting right of "<< data<<endl;
    root->right = buildTree(root->right);

    return root;

}

void levelOrderTraversal(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        if(temp==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";

            if(temp->left){
                q.push(temp->left);
            }

            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}

void inOrderTraversal(Node* root){
    //base case
    if(root==NULL)
        return;

    inOrderTraversal(root->left);
    cout<<root->data<<" ";
    inOrderTraversal(root->right);
}

void preOrderTraversal(Node* root){
    //base case
    if(root==NULL)
        return;

    cout<<root->data<<" ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

void postOrderTraversal(Node* root){
    //base case
    if(root==NULL)
        return;

    
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout<<root->data<<" ";
}


int main(){
    Node* root = NULL;
    root = buildTree(root);
    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    cout<<"Printing the tree:"<<endl;

    levelOrderTraversal(root);

    inOrderTraversal(root);

    preOrderTraversal(root);

    postOrderTraversal(root);


}