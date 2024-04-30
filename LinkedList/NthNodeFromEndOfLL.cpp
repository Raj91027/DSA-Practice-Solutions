/*

Link: https://www.geeksforgeeks.org/problems/nth-node-from-end-of-linked-list/1?page=1&category=Linked%20List&sortBy=submissions
*/











//{ Driver Code Starts
//Initial Template for C++
// C program to find n'th Node in linked list
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
#include <bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};


/* Function to get the nth node from the last of a linked list*/
int getNthFromLast(struct Node* head, int n);



/* Driver program to test above function*/

// } Driver Code Ends
/* struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

//Function to find the data of nth node from the end of a linked list.
class Solution{
public:
    int getNthFromLast(Node *head, int n)
    {
        int count=0;
        Node* temp = head;
        
        while(temp!=NULL){
            count++;
            temp = temp -> next;
        }
        //cout<<count;
        if(n>count){
            return -1;
        }
        
        int ansNode = count - n;
        
        count = 1;
        temp = head;
        
        while(count<=ansNode && temp!=NULL){
            temp = temp->next;
            count++;
        }
        
        int ans = temp->data;
        return ans;
        
    }
};



//{ Driver Code Starts.

int main()
{
  int T,i,n,l,k;

    cin>>T;

    while(T--){
    struct Node *head = NULL,  *tail = NULL;

        cin>>n>>k;
        int firstdata;
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
    Solution obj;
    cout<<obj.getNthFromLast(head, k)<<endl;
    }
    return 0;
}
// } Driver Code Ends