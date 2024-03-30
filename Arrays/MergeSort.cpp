











//{ Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;



/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


// } Driver Code Ends
class Solution
{
    public:
    void merge(int arr[], int s, int m, int e)
    {
        int len1 = m-s+1;
        int len2 = e-m;
        
        int *first = new int[len1];
        int *second = new int[len2];
        int mainIndex= s;
        
        for(int i=0;i<len1;i++){
            first[i]=arr[mainIndex++];
        }
        
        mainIndex = m+1;
        
        for(int i=0;i<len2;i++){
            second[i]=arr[mainIndex++];
        }
        
        int index1 = 0;
        int index2 =0;
        mainIndex = s;
        
        while(index1 < len1 && index2 < len2){
            if(first[index1]<second[index2]){
                arr[mainIndex++]=first[index1++];
            }
            else{
                arr[mainIndex++]=second[index2++];
            }
        }
        
        while(index1<len1){
            arr[mainIndex++]=first[index1++];
        }
        
        while(index2<len2){
            arr[mainIndex++]=second[index2++];
        }
        
        
    }
    public:
    void mergeSort(int arr[], int s, int e)
    {
        if(s>=e)
            return;
        int mid = s +(e-s)/2;
        
        mergeSort(arr,s,mid);
        
        mergeSort(arr,mid+1,e);
        
        merge(arr,s,mid,e);
    }
};

//{ Driver Code Starts.


int main()
{
    int n,T,i;

    scanf("%d",&T);

    while(T--){
    
    scanf("%d",&n);
    int arr[n+1];
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);

    Solution ob;
    ob.mergeSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends