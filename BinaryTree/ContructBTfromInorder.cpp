/*
Link: https://www.geeksforgeeks.org/problems/tree-from-postorder-and-inorder/1
*/




class Solution {
public:
    Node* buildTreeHelper(int in[], int post[], int inStart, int inEnd, int& postIndex) {
        if (inStart > inEnd) 
            return NULL;

        Node* root = new Node(post[postIndex--]); 

        int inIndex; 
        for (int i = inStart; i <= inEnd; ++i) {
            if (in[i] == root->data) {
                inIndex = i;
                break;
            }
        }

        root->right = buildTreeHelper(in, post, inIndex + 1, inEnd, postIndex);
        root->left = buildTreeHelper(in, post, inStart, inIndex - 1, postIndex);

        return root;
    }

    Node* buildTree(int in[], int post[], int n) {
        int postIndex = n - 1; 
        return buildTreeHelper(in, post, 0, n - 1, postIndex);
    }
    
};