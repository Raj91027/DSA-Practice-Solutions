/*
 Maximum of all subarrays of size k
 (Sliding Window Maximum (Maximum of all subarrays of size K))

Given an array arr[] of size N and an integer K. 
Find the maximum for each and every contiguous subarray of size K.


Example 1:

Input:
N = 9, K = 3
arr[] = 1 2 3 1 4 5 2 3 6
Output: 
3 3 4 5 5 5 6 
Explanation: 
1st contiguous subarray = {1 2 3} Max = 3
2nd contiguous subarray = {2 3 1} Max = 3
3rd contiguous subarray = {3 1 4} Max = 4
4th contiguous subarray = {1 4 5} Max = 5
5th contiguous subarray = {4 5 2} Max = 5
6th contiguous subarray = {5 2 3} Max = 5
7th contiguous subarray = {2 3 6} Max = 6

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(k)

Constraints:
1 ≤ N ≤ 10^5
1 ≤ K ≤ N
0 ≤ arr[i] ≤ 10^7

Link:https://www.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k3101/1?page=1&sprint=ca8ae412173dbd8346c26a0295d098fd&sortBy=submissions


*/

//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    //Function to find maximum of each subarray of size k.
    vector <int> max_of_subarrays(int *arr, int N, int K)
    {
        vector <int> sub;
        std::deque<int> Qi(K);
    int i;
    for (i = 0; i < K; ++i) {
 
        
        while ((!Qi.empty()) && arr[i] >= arr[Qi.back()])
 
            
            Qi.pop_back();
 
        Qi.push_back(i);
    }

    for (; i < N; ++i) {
 
        sub.insert(sub.end(),arr[Qi.front()]);
 
        while ((!Qi.empty()) && Qi.front() <= i - K)
 
            Qi.pop_front();
 
        while ((!Qi.empty()) && arr[i] >= arr[Qi.back()])
            Qi.pop_back();
 
        Qi.push_back(i);
    }

    sub.insert(sub.end(),arr[Qi.front()]);

    
    return sub;
    }    
    
};

//{ Driver Code Starts.

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int n, k;
	    cin >> n >> k;
	    
	    int arr[n];
	    for(int i = 0;i<n;i++) 
	        cin >> arr[i];
	    Solution ob;
	    vector <int> res = ob.max_of_subarrays(arr, n, k);
	    for (int i = 0; i < res.size (); i++) 
	        cout << res[i] << " ";
	    cout << endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends

/*
    Follow the given steps to solve the problem:

Create a deque to store K elements.
Run a loop and insert the first K elements in the deque. 
Before inserting the element, check if the element at the back of the queue is smaller than the current element, 
if it is so remove the element from the back of the deque until all elements left in the deque are greater than 
the current element. Then insert the current element, at the back of the deque.
Now, run a loop from K to the end of the array.
Print the front element of the deque.
Remove the element from the front of the queue if they are out of the current window.
Insert the next element in the deque. Before inserting the element, check if the element at the back of 
the queue is smaller than the current element, if it is so remove the element from the back of the deque 
until all elements left in the deque are greater than the current element. Then insert the current element, at the back of the deque.
Print the maximum element of the last window.
*/