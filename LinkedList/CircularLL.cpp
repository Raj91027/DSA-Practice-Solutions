#include<iostream>

using namespace std;

class Node{
    public:
    int data;
    Node* next;
    //constructor 
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
    //destructor
    ~Node(){
        if(this->next!=NULL){
            delete next;
            this->next = NULL;
        }
    }


};

//traverse circularLL

void print(Node* tail){
    Node* temp = tail;
    if(tail == NULL){
        cout << "List is empty"<< endl;
        return;
    }

    do{
        cout << tail->data << " ";
        tail = tail->next;
    }while(tail!=temp);
    cout << endl;

}

//insertion of node

void insertNode(Node* &tail, int element, int d){
    // empty list
    if(tail==NULL){
        Node* temp = new Node(d);
        tail = temp;
        temp->next = temp;
    }
    else{
        //non-empty list
        //assuming that the element is present in the list

        Node* curr = tail;
        while(curr->data != element){
            curr = curr->next;
        }

        //element found -> curr is representing element
        Node* temp = new Node(d);
        temp ->next = curr ->next;
        curr->next = temp;
    }
}

//deletion of node

void deleteNode(Node* &tail, int value){
    //empty list
    if(tail == NULL) {
        cout << " List is empty!" << endl;
        return;
    }
    else{
        //non-emptu
        //assuming element is present

        Node* prev = tail;
        Node* curr = prev -> next;

        while(curr -> data != value){
            prev = curr;
            curr = curr -> next;
        }

        
        prev -> next = curr -> next;
        if(curr == prev){
            tail = NULL;
        }

        else if(tail == curr){
            tail = prev;
        }
        curr -> next = NULL;
        delete curr;

    }
}

bool isCircular(Node* tail){
    
    if(tail == NULL){
        return true;
    }

    Node* temp = tail->next;

    while(temp!=tail && temp!=NULL ){
        temp = temp -> next;
    }

    if(temp==tail){
        return true;
    }
    else{
        return false;
    }
}
//main function
int main(){
    Node* tail = NULL;

    insertNode(tail,5 ,3);
    print(tail);
/*
    insertNode(tail,3,5);
    print(tail);

    insertNode(tail,5,7);
    print(tail);

    insertNode(tail,3,9);
    print(tail);

    insertNode(tail,9,2);
    print(tail);

    
    insertNode(tail, 7, 10);
    print(tail);

    deleteNode(tail, 3);
    print(tail);
    */
   if(isCircular(tail)){
    cout << "It is circular." << endl;
   }
   else{
    cout << "Not circular."<<endl;
   }

    return 0;

}