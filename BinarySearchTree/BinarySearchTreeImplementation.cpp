// Online C++ compiler to run C++ program online
#include<iostream>
#include<queue>
using namespace std;

class Node{

    public:
        int data;
        Node* left;
        Node* right;

        Node(int d){
            this -> data = d;
            this->left = NULL;
            this -> right = NULL;
        }
};

//minimum data in a BST
Node* minInBST(Node* root){
    Node* temp = root;

    while(temp->left !=NULL){
        temp = temp->left;
    }
    return temp;
}

//maximun data in a BST
Node* maxInBST(Node* root){
    Node* temp = root;

    while(temp->right != NULL){
        temp = temp -> right;
    }
    return temp;
}

//Search in a BST
bool searchInBST(Node* root, int x) {
    Node* temp = root;

    while(temp!= NULL){
        if(temp->data==x){
            return true;
        }

        if(temp->data > x){
            temp = temp -> left;
        }
        else{
            temp = temp -> right;
        }
    }
    return false;
}

// Level order Traversal 
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

//inOrder traversal , it gives data in sorted order
void inOrderTraversal(Node* root){
    //base case
    if(root==NULL){
        return;
    }

    inOrderTraversal(root->left);
    cout<<root->data<<" ";
    inOrderTraversal(root->right);
}

//deletion from BST

Node* deleteFromBST(Node* root, int x){
    //base case
    if(root==NULL){
        return root;
    }

    if(root->data == x){
        //node with 0 child
        if(root->left==NULL && root->right==NULL){
            delete root;
            return NULL;
        }
        // node with 1 child
        // node with left child
        if(root->left != NULL && root->right == NULL){
            Node* temp = root ->left;
            delete root;
            return temp;
        }
        //node with right child
        if(root->left == NULL && root->right != NULL){
            Node* temp = root ->right;
            delete root;
            return temp;
        }
        //node with two child
        if(root->left!=NULL && root->right != NULL){
            int mini = minInBST(root->right) -> data;
            root->data = mini;
            root->right = deleteFromBST(root->right, mini);
            return root;
        }

    }
    else if(root->data < x){
        root -> right = deleteFromBST(root->right, x);
        return root;
    }
    else{
        root->left = deleteFromBST(root->left, x);
        return root;
    }
}

//Insertion in a BST
Node* insertIntoBST(Node* root, int d){
    if(root == NULL){
        root = new Node(d);
        return root;
    }

    if(d > root -> data){
        root -> right = insertIntoBST(root -> right, d);
    }
    else{
        root -> left = insertIntoBST(root -> left, d);
    }

    return root;

}
void takeInput(Node* &root){
    int data;
     cin >> data;

     while(data != -1){
        root = insertIntoBST(root, data);
        cin >> data;
     }
}
int main() {

    Node* root = NULL;

    cout<< "Enter data to create BST: "<<endl;

    takeInput(root);
    cout <<"Printing BST:"<<endl;
    levelOrderTraversal(root);
}