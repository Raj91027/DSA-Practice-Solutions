#include<iostream>

using namespace std;

class Node{
    public:
    int data;
    Node* next;
    //constructor
    Node(int data){
        this->data=data;
        this->next=NULL;
    }

    ~Node(){
        if(this->next!=NULL){
            delete next;
            this->next = NULL;
        }
    }
};
//insert at start
void insertAtHead(Node* &head,Node* &tail, int d){
    if(head==NULL){
        Node* temp = new Node(d);
        head = temp;
        tail = temp;
    }
    else{
    Node* temp = new Node(d);
    temp->next = head;
    head = temp;
    }
}

//insert at end
void insertAtTail(Node* &head, Node* &tail,int d){
    if(tail == NULL){
        Node* temp =new Node(d);
        tail = temp;
        head= temp;
    }
    else{
    Node* temp = new Node(d);
    tail -> next = temp;
    tail = tail ->next;
    }
}

//insert at position
void insertAtPosition(Node* &head,Node* &tail, int position, int d){
    Node* temp = head;
    if(position==1){
        insertAtHead(head,tail,d);
        return;
    }

   
    int cnt=1;
    while(cnt<position-1){
        temp = temp->next;
        cnt++;
    }
    if(temp->next==NULL){
        insertAtTail(head, tail,d);
        return;
    }
    Node* NodeToInsert = new Node(d);

    NodeToInsert ->next = temp->next;
    temp -> next = NodeToInsert;

}

//delete Node
void deleteNode(int position, Node* &head, Node* &tail){
    if(position==1){
        Node* temp = head;
        head = head->next;

        temp->next = NULL;
        delete temp;
    }
    else{
        Node* curr = head;
        Node* prev = NULL;
        int cnt = 1;

        while(cnt < position){
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        if(curr -> next==NULL){
            tail = prev;
        }
        prev -> next = curr -> next;
        curr -> next = NULL;
        delete curr;
    }
}
//print linked list
void print(Node* &head){
    Node* temp = head;
    while(temp!=NULL){
        cout << temp->data <<" ";
        temp = temp ->next;
    }
    cout << endl;
}

// Reversing a Linked List elements

void reverse(Node* &head){
    Node* prev = NULL;
    Node* curr = head;

    while(curr!=NULL){
        Node* forward = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = forward;
    }
    
    head = prev;
}
// Reverse in K groups

Node* kReverse(Node* head, int k){
    //base case 
    if(head==NULL && k==1){
        return head;
    }

    //count number of nodes in remaining list
    Node* temp = head;
    int cnt =1;
    while(temp->next !=NULL){
        temp = temp->next;
        ++cnt;
    }

    // if list has less nodes than k ,return head. No need to reverse

    if(cnt<k){
        return head;
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
        head -> next = kReverse(forward, k);
    }

    return prev;

}

// Find middle of Linked List

void findMiddleOfLL(Node* &head){
    Node* slow = head;
    Node* fast = head;
    cout << slow->data << endl;
    while(fast!=nullptr && fast->next!=nullptr){
        slow = slow -> next;
        fast = fast -> next;
        fast = fast -> next;
    }

    cout << slow->data << endl;
    //return slow;
}

int main(){

    Node* node1 = new Node(10);
    //cout << node1->data <<endl;
    //cout << node1->next <<endl;
    Node* head = node1;
    Node* tail = node1;

    print(head);

    insertAtHead(head,tail,12);
    print(head);

    insertAtHead(head,tail,15);
    print(head);

    insertAtTail(head,tail,22);
    print(head);

    insertAtPosition(head, tail,1, 5);
    print(head);
    
    insertAtPosition(head,tail,6,11);
    print(head);

    // cout << "head: " << head->data << endl;
    // cout << "Tail: " << tail->data << endl;

    // deleteNode(4, head,tail);
    // print(head);

    // cout << "head: " << head->data << endl;
    // cout << "Tail: " << tail->data << endl;
    // reverse(head);
    // print(head);
    
    // findMiddleOfLL(head);

    //cout << res -> data;

    head = kReverse(head, 4);
    print(head);
    
    return 0;

}