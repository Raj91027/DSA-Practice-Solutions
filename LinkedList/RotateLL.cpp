/*

LInk: https://www.geeksforgeeks.org/problems/rotate-a-linked-list/1?page=1&category=Linked%20List&sortBy=submissions
*/



//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
/*

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/


class Solution
{
    public:
    //Function to rotate a linked list.
    Node* rotate(Node* head, int k)
    {
        if(head == NULL){
            return NULL;
        }
        
        Node* temp = head;
        int count = 0;
        
        while(temp!=NULL){
            temp = temp->next;
            count++;
        }
        
    
        if(k==0 || k==count){
            return head;
        }
        
        temp = head;
        while(k > 1){
            temp = temp -> next;
            k--;
        }
        
        Node* headToRev = temp -> next;
        
        temp -> next = NULL;
        
        Node* curr = headToRev;
        
        while(curr -> next != NULL){
            curr = curr -> next;
        }
        
        curr -> next = head;
        
        head = headToRev;
        
        return head;
        
    }
};
    


//{ Driver Code Starts.

void printList(Node *n)
{
    while (n != NULL)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, val, k;
        cin>>n;
        
        cin>> val;
        Node *head = new Node(val);
        Node *tail = head;
        
        for(int i=0; i<n-1; i++)
        {
            cin>> val;
            tail->next = new Node(val);
            tail = tail->next;
        }
        
        cin>> k;
        
        Solution ob;
        head = ob.rotate(head,k);
        printList(head);
    }
    return 1;
}

// } Driver Code Ends