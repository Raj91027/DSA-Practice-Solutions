






Node* minInBST(Node* root){
    Node* temp = root;

    while(temp->left !=NULL){
        temp = temp->left;
    }
    return temp;
}


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