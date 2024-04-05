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

    cout << "head: " << head->data << endl;
    cout << "Tail: " << tail->data << endl;

    deleteNode(4, head,tail);
    print(head);

    cout << "head: " << head->data << endl;
    cout << "Tail: " << tail->data << endl;

    return 0;

}