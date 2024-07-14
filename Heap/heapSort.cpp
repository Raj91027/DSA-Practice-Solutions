#include<iostream>

using namespace std;

void heapify(int arr[], int n, int i){
    int largest = i;
    int leftIndex = 2*i;
    int rightIndex = 2*i+1;

    if(leftIndex <= n && arr[largest] < arr[leftIndex]){
        largest = leftIndex;
    }
    if(rightIndex <= n && arr[largest] < arr[rightIndex]){
        largest = rightIndex;
    }

    if(largest != i){
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n){
    int size = n;

    while(size > 1){
        swap(arr[size], arr[1]);

        size--;

        heapify(arr, n, 1);
    }

}


int main(){

    int arr[6] = {-1, 54, 53, 55, 52, 50};
    int n = 5;
    for(int i= n/2 ; i>0; i--){
        heapify(arr, n, i);
    }

    for(int i=1; i<=n; i++){
        cout << arr[i]<< " ";
    }cout << endl;

    heapSort(arr, n);

    for(int i=1; i<=n; i++){
        cout << arr[i]<< " ";
    }cout << endl;

    return 0;
}