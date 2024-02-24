/* Kth smallest element by using Binary Search
 * Solution of DSA Sheet by Love Babar 
 * Code written by: Raj Kumar Yadav
 * Given an array arr[] and an integer K where K is smaller than size of array, 
 * the task is to find the Kth smallest element in the given array. 
 * It is given that all array elements are distinct.
 * Input:
N = 6
arr[] = 7 10 4 3 20 15
K = 3
L=0 R=5

Output : 7
Explanation :
3rd smallest element in the given 
array is 7.
Link to Question: https://www.geeksforgeeks.org/problems/kth-smallest-element5635/1

 */

 //{ Driver Code Starts
//Initial Template for Java

/*package whatever //do not write package name here */

import java.io.*;
import java.util.*;
class GFG {
	public static void main (String[] args) {
		Scanner sc=new Scanner(System.in);
		PrintWriter out = new PrintWriter(System.out);
		int t=sc.nextInt();
		
		while(t-->0)
		{
		    int n=sc.nextInt();
		    
		    int arr[]=new int[n];
		    
		    for(int i=0;i<n;i++)
		    arr[i]=sc.nextInt();
		    
		    int k=sc.nextInt();
		    Solution ob = new Solution();
		    out.println(ob.kthSmallest(arr, 0, n-1, k));
		}
		out.flush();
	}
}

// } Driver Code Ends


//User function Template for Java

class Solution{
    
    
    public static int kthSmallest(int[] nums, int l, int r, int k) 
    { 
        int low = Integer.MAX_VALUE;
        int high = Integer.MIN_VALUE;

        for(int i=0; i<nums.length; i++){
            low = Math.min(low,nums[i]);
            high = Math.max(high, nums[i]);

        }
        while(low<high){
            int mid = low+ (high-low)/2;
            if(count(nums, mid) < k)
                low = mid+1;
            else
                high = mid;
        }
        return low;
    } 
}





/*Another Approach By using inbuilt sorting method.

 * Sort the input array in the increasing order
   Return the element at the K-1 index (0 – Based indexing) in the sorted array


 */






 //{ Driver Code Starts
//Initial Template for Java

/*package whatever //do not write package name here */

import java.io.*;
import java.util.*;
class GFG {
	public static void main (String[] args) {
		Scanner sc=new Scanner(System.in);
		PrintWriter out = new PrintWriter(System.out);
		int t=sc.nextInt();
		
		while(t-->0)
		{
		    int n=sc.nextInt();
		    
		    int arr[]=new int[n];
		    
		    for(int i=0;i<n;i++)
		    arr[i]=sc.nextInt();
		    
		    int k=sc.nextInt();
		    Solution ob = new Solution();
		    out.println(ob.kthSmallest(arr, 0, n-1, k));
		}
		out.flush();
	}
}

// } Driver Code Ends


//User function Template for Java

class Solution{
    
    
    public static int kthSmallest(int[] arr, int l, int r, int k) 
    { 
        Arrays.sort(arr);
        return arr[k-1];
    } 
}

