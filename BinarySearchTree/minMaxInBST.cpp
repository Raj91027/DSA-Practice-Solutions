
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