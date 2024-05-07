#include<iostream>
#include<stack>

using namespace std;

class Stack {
    //properties
    public:
    int top;
    int *arr;
    int size;

    //constructor

    Stack(int size){
        this -> size = size;
        arr = new int[size];
        this -> top = -1;
    }

    //behaviour
    void push(int element){
        if(size - top > 1){
            top++;
            arr[top] = element;
        }
        else{
            cout << "Stack Overflow"<< endl;
        }
    }

    void pop(){
        if(top >=0){
            top--;
        }
        else{
            cout << "Stack underflow"<< endl;
        }
    }

    int peek(){
        if(top >= 0){
            return arr[top];
        }
        else{
            cout <<"Stack is empty."<<endl;
            return -1;
        }
    }

    bool isEmpty(){
        if(top == -1){
            return true;
        }
        else{
            return false;
        }
    }

};


int main(){

    Stack s(5);
    s.push(10);
    s.push(20);
    s.push(30);
    

    cout <<"Top element is:"<<s.peek()<<endl;

    s.pop();

    cout <<"Top element is:"<<s.peek()<<endl;

    s.pop();

    cout <<"Top element is:"<<s.peek()<<endl;
    
    s.pop();

    if(s.isEmpty()){
        cout<<"Stack is empty"<<endl;
    }
    else{
        cout<<"Stack is not empty."<<endl;
    }
    //s.pop();


    /*
    stack<int> s;
    s.push(10);
    s.push(20);
    cout<<"top element is:"<<s.top()<<endl;

    s.pop();
    cout<<"top element is:"<<s.top()<<endl;
    s.pop();

    if(s.empty()){
        cout <<"Stack is empty."<<endl;
    }
    else{
        cout <<"Stack is not empty."<< endl;
    }
    */

   return 0;
}