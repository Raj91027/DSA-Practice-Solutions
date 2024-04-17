#include<iostream>

using namespace std;



class Node
{
    public:
	    int data;
	    Node *next;
	    Node(int data)
	   {
        this->data = data;
		this->next = NULL;
	    }
};



Node* kReverse(Node* head, int n,int b[], int index){
    //base case
	if(head==NULL || index>=n){
		return head;
	}
    
	int k = b[index];
	if(k==0 )
    {
        return kReverse(head,n,b,index+1);
    }
	
   
    Node* forward = NULL;
    Node* curr = head;
    Node* prev = NULL;

    int count =0;

    while(curr != NULL && count < k){
        forward = curr ->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
        count++;
    }
	
    if(forward != NULL){
        head -> next = kReverse(forward, n, b,index+1);
    }

    return prev;

}

Node *getListAfterReverseOperation(Node *head, int n, int b[]){
    if(head==NULL){
        return NULL;
    }
	return kReverse(head,n,b,0);
}


int main(){
    
}