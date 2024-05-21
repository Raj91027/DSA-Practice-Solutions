
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

// Build Tree from Level order Traversal

void BuildTreeFromLOT(Node* &root){
    queue<Node*> q;
    int data;
    cout<<"Enter data"<<endl;
    cin >> data;
    root = new Node(data);

    q.push(root);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        cout<<"Enter the left node for:"<<temp->data<<endl;
        int leftData;
        cin >> leftData;

        if(leftData!= -1){
            temp->left = new Node(leftData);
            q.push(temp->left);
        }

        cout<<"Enter the right node for:"<<temp->data<<endl;
        int rightData;
        cin >> rightData;

        if(rightData!= -1){
            temp->right = new Node(rightData);
            q.push(temp->right);
        }
    }
}

// Level Order Traversal

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

int main(){
    Node* root = NULL;

    BuildTreeFromLOT(root);
    // 1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1
    cout<<"Printing tree by Level Order Traversal:"<<endl;

    levelOrderTraversal(root);


    return 0;
}