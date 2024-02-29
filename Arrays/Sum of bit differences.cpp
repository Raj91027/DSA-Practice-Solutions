/*
Sum of bit differences

Given an array integers arr[], containing n elements, find the sum of bit differences 
between all pairs of element in the array. Bit difference of a pair (x, y) is the count 
of different bits at the same positions in binary representations of x and y.
For example, bit difference for 2 and 7 is 2. Binary representation of 2 is 010 and 7 is 
111 respectively and the first and last bits differ between the two numbers.

Example 1:

Input: 
n = 2
arr[] = {1, 2}
Output: 4
Explanation: All possible pairs of an array are (1, 1), (1, 2), (2, 1), (2, 2).
Sum of bit differences = 0 + 2 + 2 + 0 = 4
                       
Note: (x, y) and (y, x) are considered two separate pairs.

Expected Time Complexity: O(n).
Expected Auxiliary Space: O(1).

Constraints:
1 <= n <= 10^5
1 <= arr[i] <= 10^5

Link: https://www.geeksforgeeks.org/problems/sum-of-bit-differences2937/1
*/





//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	
	long long sumBitDifferences(int arr[], int n) {
        long long out = 0;
        for(int i=0; i<32; ++i){
            long long one = 0;
            for(int j = 0; j < n; ++j)
                if((arr[j]&(1<<i))!=0)
                    ++one;
            long long zero = n - one;
            out += 2*one*zero;
        }
        return out;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.sumBitDifferences(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends
