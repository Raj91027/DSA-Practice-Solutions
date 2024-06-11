

/*
Link: https://www.geeksforgeeks.org/problems/flatten-binary-tree-to-linked-list/1
*/





class Solution
{
    public:
    void flatten(Node *root)
    {
        Node* curr = root;
        while(curr!=NULL){
            if(curr->left){
                Node* pred = curr -> left;
                while(prev -> right){
                    pred = prev->right;
                }
                
                pred ->right = curr -> right;
                curr -> right = curr -> left;
                curr -> left = NULL;
            }
            
            curr = curr -> right;
        }
    }
};