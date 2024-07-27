class Solution{
    public:
    
    void heapify(vector<int> &arr, int n, int i){
        int largest = i;
        int leftIndex = 2*i+1;
        int rightIndex = 2*i+2;
    
        if(leftIndex < n && arr[largest] < arr[leftIndex]){
            largest = leftIndex;
        }
        if(rightIndex < n && arr[largest] < arr[rightIndex]){
            largest = rightIndex;
        }
    
        if(largest != i){
            swap(arr[largest], arr[i]);
            heapify(arr, n, largest);
        }
    }
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        //step-1 : merge two vectors
        vector<int> ans;
        
        for(auto i:a)
            ans.push_back(i);
            
        for(auto i:b)
            ans.push_back(i);
        
        //step-2: Build heap from merged array
        int size = ans.size();
        for(int i=size/2 - 1; i>=0; i--){
            heapify(ans, size,i);
        }
    
        return ans;
    }
};