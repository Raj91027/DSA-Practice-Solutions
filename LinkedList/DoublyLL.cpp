#include<iostream>

using namespace std;

class Node{
    public:
    int data;
    Node* prev;
    Node* next;

    Node(int data){
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
    ~Node(){
        if(this->next!=NULL){
            delete next;
            this->next = NULL;
        }
    }
};
//print Doublyll
void print(Node* &head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data << " ";
        temp = temp->next;
    }
    cout<<endl;
}
//gives length of LL
int findLength(Node* &head){
    Node* temp = head;
    int len=0;
    while(temp!=NULL){
        len++;
        temp = temp->next;
    }
    return len;
}

//insertion at head

void insertAtHead(Node* &head,Node* &tail, int d){
    if(head==NULL){
        Node* temp = new Node(d);
        head = temp;
        tail = temp;
    }
    else{
        Node* temp = new Node(d);

        temp ->next = head;
        head->prev = temp;
        head = temp;
    }
    
}
//insert at tail 
void insertAtTail(Node* &head, Node* &tail, int d){
    if(tail == NULL){
        Node* temp =new Node(d);
        tail = temp;
        head= temp;
    }
    else{
    Node* temp = new Node(d);
    temp ->prev = tail;
    tail->next = temp;
    tail = tail->next;
    }
}

//insertion at position
void insertAtPos(Node* &head, Node* &tail, int position, int d){
    if(position==1){
        insertAtHead(head,tail, d);
        return;
    }

    int cnt=1;
    Node*temp = head;
    while(cnt<position-1){
        temp = temp->next;
        cnt++;
    }
    if(temp->next==NULL){
        insertAtTail(head,tail,d);
        return;
    }

    Node* nodeToInsert = new Node(d);

    nodeToInsert->next = temp->next;
    temp->next->prev = nodeToInsert;
    temp->next = nodeToInsert;
    nodeToInsert->prev = temp;
}

//delete node
void deleteNode(int position, Node* &head, Node* &tail){
    //deleting first node
    if(position==1){
        Node* temp = head;
        head = head->next;
        head->prev = NULL;

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
        if(curr -> next == NULL){
            tail = prev;
        }
        curr ->prev = NULL;
        prev-> next = curr->next;
        curr->next = NULL;

        delete curr;
        }
    }

int main(){
    //Node* node1 = new Node(10);
    Node* head = NULL;
    Node* tail = NULL;
    print(head);
    //cout << findLength(head);

    insertAtHead(head, tail, 12);
    print(head);
    //cout << findLength(head);
    insertAtHead(head,tail, 13);
    print(head);

    insertAtTail(head, tail, 8);
    print(head);

    //cout << findLength(head);

    insertAtTail(head,tail, 7);
    print(head);
    
    insertAtPos(head,tail,3,11);
    print(head);

    insertAtPos(head,tail,3,32);
    print(head);
    cout << "head: " << head->data << endl;
    cout << "Tail: " << tail->data << endl;

    deleteNode(6,head,tail);
    print(head);
    // deleteNode(3,head,tail);
    // print(head);
    cout << "head: " << head->data << endl;
    cout << "Tail: " << tail->data << endl;
    
    return 0;

}