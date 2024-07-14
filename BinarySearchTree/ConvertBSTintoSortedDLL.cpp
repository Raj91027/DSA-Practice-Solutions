class Node
    {
    public:
        int data;
        Node *left, *right;
        Node() : data(0), left(NULL), right(NULL) {}
        Node(int x) : data(x), left(NULL), right(NULL) {}
        Node(int x, Node *left, Node *right) : data(x), left(left), right(right) {}
    };

void convertIntoSortedDLL(Node* root, Node* &head){
    if(root==NULL){
        return;
    }

    convertIntoSortedDLL(root->right,head);
    root->right = head;
    if(head!=NULL)
        head->left = root;

    head = root;

    convertIntoSortedDLL(root->left,head);
}