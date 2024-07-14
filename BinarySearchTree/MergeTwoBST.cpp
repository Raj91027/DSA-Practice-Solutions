/*************************************************************

    Following is the Binary Tree node structure:

    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };

*************************************************************/
void inorder(TreeNode* root, vector<int> &in){
    if(root==NULL)
        return;
    
    inorder(root->left,in);
    in.push_back(root->data);
    inorder(root->right,in);
}
vector<int> mergeTwoSortedArray(vector<int> arr1, vector<int> arr2){
    int n = arr1.size();
    int m = arr2.size();
    int i = 0, j = 0;
    vector<int> res;

    while (i < n && j < m) {
        if (arr1[i] < arr2[j])
            res.push_back(arr1[i++]);
        else {
            res.push_back(arr2[j++]);
        }
    }
               
    while(i<n){
        res.push_back(arr1[i++]);
    }
    while(j<m){
        res.push_back(arr2[j++]);
    }
    return res;
}
/*
TreeNode* inOrderToBST(int s, int e, vector<int> &in){
    if(s>e){
        return NULL;
    }

    int mid = (s+e)/2;
    TreeNode* root = new TreeNode(in[mid]);
    root->left = inOrderToBST(s,mid-1,in);
    root->right = inOrderToBST(mid+1,e,in);
    return root;
}
*/

void convertIntoDLL(TreeNode *root, TreeNode* &head){
    if(root==NULL){
        return;
    }

    convertIntoDLL(root->right,head);
    root->right = head;
    if(head!=NULL)
        head->left = root;

    head = root;
    convertIntoDLL(root->left,head);
}

TreeNode* mergeTwoSortedLL(TreeNode *head1, TreeNode *head2){
    Node* head = NULL;
    Node* tail = NULL;

    while(head1!=NULL && head2!=NULL){
        if(head1->data < head2->data){
            if(head==NULL){
                head = head1;
                tail = head1;
            }
            else{
                tail->right = head1;
                head1->left = tail;
                tail = head1;
                head1 = head1->right;
            }
        }
        else{
            if(head==NULL){
                head = head2;
                tail = head2;
            }
            else{
                tail->right = head2;
                head2->left = tail;
                tail = head2;
                head2 = head2->right;
            }
        }
    }

    while(head1!=NULL){
        tail->right = head1;
        head1->left = tail;
        tail = head1;
        head1 = head1->right;
    }
    while(head2!=NULL){
        tail->right = head2;
        head2->left = tail;
        tail = head2;
        head2 = head2->right;
    }

    return head;
}
int countNodes(TreeNode* head){
    int cnt = 0;
    while(head!=NULL){
        cnt++;
        head=head->right;
    }
    return cnt;
}
TreeNode* sortedLLToBST(TreeNode* head, int n){
    if(n <= 0 && head==NULL){
        return NULL;
    }

    TreeNode* left = sortedLLToBST(head, n/2);

    TreeNode* root = head;
    root->left = left;

    head = head->right;

    root->right = sortedLLToBST(head,n-(n/2)-1);
    return root;
}


vector<int> mergeBST(TreeNode *root1, TreeNode *root2)
{
    vector<int> BST1;
    vector<int> BST2;
    //find inorder of bST1 and bst2
    inorder(root1,BST1);
    inorder(root2,BST2);
    
    //merge to sorted array
    vector<int> inOrderVal = mergeTwoSortedArray(BST1,BST2);

    return inOrderVal;

    //Instead of returning the array of inorder we can generate BST using Inorder.

    //call inorderToBST(s,e,inOrderVal)
    
//Approach-2

//converting bst to linked list
    TreeNode *head1 = NULL;
    convertIntoDLL(root1,head1);
    head1->left = NULL;
    TreeNode* head2 = NULL;
    convertIntoDLL(root2, head2);
    head2->left = NULL;
//merging two sorted LL

    TreeNode* head = mergeTwoSortedLL(head1,head2);

//converting sorted LL into BST
    int count = countNodes(head);
    TreeNode* root = sortedLLToBST(head, count);

    return root;

}