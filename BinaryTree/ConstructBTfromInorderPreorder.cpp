/**
 * 
 Link: https://www.geeksforgeeks.org/problems/construct-tree-1/1
 * 
*/


class Solution{
    public:
    int findPosition(int in[], int ele, int s, int e){
        for(int i=s;i<=e;i++)
        {
            if(in[i]==ele)
            {
                return i;
            }
        }
        return -1;
    }
    
    Node* solve(int in[], int pre[], int &index, int inOrderStart, int inOrderEnd, int n){
        //base case
        
        if(index >= n || inOrderStart > inOrderEnd){
            return NULL;
        }
        
        int element = pre[index++];
        Node* root = new Node(element);
        
        int position = findPosition(in, element, inOrderStart, inOrderEnd);
        
        root->left = solve(in, pre, index, inOrderStart, position - 1, n);
        root->right = solve(in, pre, index, position + 1, inOrderEnd, n);
        
        return root;
        
    }
    Node* buildTree(int in[],int pre[], int n)
    {
        int preOrderIndex = 0;
        Node* ans = solve(in, pre, preOrderIndex, 0, n-1, n);
        return ans;
    }
};