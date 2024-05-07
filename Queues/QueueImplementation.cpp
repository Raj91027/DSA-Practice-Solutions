#include<iostream>
using namespace std;

class Queue{
    int *arr;
    int front; 
    int rear;
    int size;

    public:
    Queue(int size){
        size = size;
        arr = new int[size];
        front = 0;
        rear = 0;
    }
    void enqueue(int data){
        if(rear==size){
            cout<<"Queue is full"<<endl;
        }

        arr[rear] = data;
        rear++;
    }

    void dequeue(){
        if(rear == front){
            cout <<"Queue is Empty."<<endl;
        }

        arr[front] = -1;
        front++;

        if(front == rear){
            front = 0;
            rear = 0;
        }
    }

    bool isEmpty(){
        if(rear == front){
            return true;
        }
        else{
            return false;
        }
    }

    int qFront(){
        if(rear == front){
            cout <<"Queue is Empty."<<endl;
            return -1;
        }
        else{
            return arr[front];
        }
    }

    int Qsize(){


        return rear-front;
    }
};

int main(){

    Queue q(5);

    q.enqueue(10);
    q.enqueue(11);
    q.enqueue(12);

    cout<<"The size of queue is:"<<q.Qsize()<<endl;

    q.dequeue();
    
    cout<<"The front is:"<<q.qFront()<<endl;
    q.dequeue();
    cout<<"The front is:"<<q.qFront()<<endl;

    if(q.isEmpty()){
        cout<<"Queue is empty."<<endl;
    }
    else{
        cout<<"Queue is not empty."<<endl;
    }
    
}





