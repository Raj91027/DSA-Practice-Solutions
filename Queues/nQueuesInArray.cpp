#include<iostream>

using namespace std;

class kQueue {
    int n, k;
    int *arr;
    int *next;
    int *front;
    int *rear;
    int freespot;

    public:
    
    kQueue(int n, int k){
        this -> n = n;
        this -> k = k;
        arr = new int[n];
        next = new int[n];
        front = new int[k];
        rear = new int[k];
        freespot = 0;
        
        for(int i=0; i<k; i++){
            front[i] = -1;
            rear[i] = -1;
        }

        for(int i=0; i<n; i++){
            next[i] = i+1;
        }
        next[n-1] = -1;
    }

    void push(int q, int x){
        if(freespot == -1){
            cout<<"Overflow"<<endl;
            return;
        }
        //find index
        int index = freespot;
        // update freespot
        freespot = next[index];

        //first element

        if(front[q-1] == -1){
            front[q-1] = index;
        }
        else{
            next[rear[q-1]] = index;
        }
        //update next
        next[index] = -1;
        //update rear
        rear[q-1] = index;
        //push data
        arr[index] = x;
    }

    int pop(int q){
        if(front[q-1] == -1){
            return -1;
        }
        //find index
        int index = front[q-1];
        //update front
        front[q-1] = next[index];
        //update next
        next[index] = freespot;
        //update freespot
        freespot = index;

        return arr[index];
    }
};

int main(){

    kQueue q(7,3);
    // q.push(1,10);
    // q.push(1,17);
    // q.push(2,20);
    // q.push(1,15);
    // q.push(3,11);

    // cout<<q.pop(1)<<endl;
    // cout<<q.pop(1)<<endl;
    // cout<<q.pop(2)<<endl;
    // cout<<q.pop(1)<<endl;

    // cout<<q.pop(3)<<endl;

    q.push(3,11);
    q.push(1,17);
    q.push(2,20);
    q.push(1,15);
    
    cout<<q.pop(1)<<endl;
    cout<<q.pop(1)<<endl;
    cout<<q.pop(2)<<endl;
    cout<<q.pop(1)<<endl;

    cout<<q.pop(3)<<endl;

    return 0;
}