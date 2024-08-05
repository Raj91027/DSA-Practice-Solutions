#include<limits.h>
#include<queue>

class node{
    public:
    int data;
    int row;
    int col;

    node(int d, int r, int c){
        data = d;
        row = r;
        col = c;
    }
};

class compare{
    public:
    bool operator()(node* a, node* b){
        return a->data > b-> data;
    }
};

int kSorted(vector<vector<int>> &a, int k, int n) {
    int mini = INT_MAX, maxi = INT_MIN;

    priority_queue<node*, vector<node*>, compare>minHeap;

    for(int i=0; i<k; i++){
        int ele = a[i][0];
        mini = min(mini, ele);
        maxi = max(maxi,ele);

        minHeap.push(new node(ele,i,0));
    }


    int start = mini, end = maxi;

    while(!minHeap.empty()){
        node* temp = minHeap.top();
        minHeap.pop();

        mini = temp ->data;

        if(maxi - mini < end - start){
            start = mini;
            end = maxi;
        }

        if(temp->col +1 < n){
            maxi = max(maxi, a[temp->row][temp->col+1]);
            minHeap.push(new node(a[temp->row][temp->col+1],temp->row, temp->col+1));
        }
        else{
            break;
        }
        
    }
    return (end - start +1);
}