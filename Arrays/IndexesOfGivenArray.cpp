/*
Find Indexes of a subarray with given sum
Link: https://www.geeksforgeeks.org/problems/subarray-with-given-sum-1587115621/1?page=1&sortBy=submissions

Given an unsorted array A of size N that contains only non negative integers, find a continuous sub-array that adds to a given number S and return the left and right index(1-based indexing) of that subarray.

In case of multiple subarrays, return the subarray indexes which come first on moving from left to right.

Note:- You have to return an ArrayList consisting of two elements left and right. In case no such subarray exists return an array consisting of element -1.

Example 1:

Input:
N = 5, S = 12
A[] = {1,2,3,7,5}
Output: 2 4
Explanation: The sum of elements 
from 2nd position to 4th position 
is 12.

Approach:
Create two variables, start=0, Sum = arr[0]
Traverse the array from index 1 to end.
Update the variable Sum by adding current element, Sum = Sum + arr[i]
If the Sum is greater than the given sum, update the variable Sum as Sum = Sum – arr[start],
and update start as, start++.
If the Sum is equal to given sum, print the subarray and break the loop.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)

*/





//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(vector<int>arr, int n, long long s)
    {
        long long Sum = arr[0];
        int start =0, i;
        
        for(i=1;i<=n;i++) {
            while(Sum > s && start < i-1){
                Sum = Sum - arr[start];
                start++;
            }
            
            if(Sum == s){
                return {start+1, i};
            }
            if(i<n)
                Sum =Sum + arr[i];
        }
        return {-1};
    }
};

//{ Driver Code Starts.

int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        long long s;
        cin>>n>>s;
        vector<int>arr(n);
        // int arr[n];
        const int mx = 1e9;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        vector<int>res;
        res = ob.subarraySum(arr, n, s);
        
        for(int i = 0;i<res.size();i++)
            cout<<res[i]<<" ";
        cout<<endl;
        
    }
	return 0;
}
// } Driver Code Ends