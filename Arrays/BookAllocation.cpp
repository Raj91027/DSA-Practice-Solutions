/*Allocate minimum number of pages
You have N books, each with A[i] number of pages. M students need to be allocated contiguous books, with each student getting at least one book.
Out of all the permutations, the goal is to find the permutation where the sum of maximum number of pages in a book allotted to a student should be minimum, out of all possible permutations.

Note: Return -1 if a valid assignment is not possible, and allotment should be in contiguous order (see the explanation for better understanding).

 

Example 1:

Input:
N = 4
A[] = {12,34,67,90}
M = 2
Output:113
Explanation:Allocation can be done in 
following ways:
{12} and {34, 67, 90} Maximum Pages = 191
{12, 34} and {67, 90} Maximum Pages = 157
{12, 34, 67} and {90} Maximum Pages =113.
Therefore, the minimum of these cases is 113,
which is selected as the output.


*/




//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    bool isPossible(int A[], int n, int m, int mid){
        int studentCount =1;
        int pagesSum = 0;
        for(int i=0;i<n;i++){
            if(pagesSum+A[i]<=mid){
                pagesSum+=A[i];
            }
            else{
                studentCount++;
                if(studentCount>m || A[i]>mid){
                    return false;
                }
                pagesSum = A[i];
            }
        }
        return true;
    }
    
    
    //Function to find minimum number of pages.
    int findPages(int A[], int N, int M) 
    {
        if(M>N)
            return -1;
        int s =0;
        int sum=0;
        for(int i=0;i<N;i++){
            sum+=A[i];
        }
        int e = sum;
        int ans = -1;
        int mid = s + (e-s)/2;
        while(s<=e){
            if(isPossible(A,N,M,mid)){
                ans = mid;
                e = mid-1;
            }
            else{
                s = mid+1;
            }
            mid = s + (e-s)/2;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends