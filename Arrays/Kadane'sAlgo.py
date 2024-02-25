#Time Complexity: O(n)
#Algo's Objective: Maximum Sum of Contiguous Subarray


def kadanealgo(arr):
    maximum = min(arr)
    cur = 0
    for i in range(len(arr)):
        cur = cur + arr[i]
        if cur > maximum:
            maximum = cur
        if cur < 0:
            cur = 0
    return

arr = [-2, -3, 4, -1, -2, 1, 5, -3]
print(kadanealgo(arr))


#GFG Question Link: https://www.geeksforgeeks.org/problems/kadanes-algorithm-1587115620/1

#solution in python...

#User function Template for python3

class Solution:
    ##Complete this function
    #Function to find the sum of contiguous subarray with maximum sum.
    def maxSubArraySum(self,arr,N):
        maximum = min(arr)
        cur = 0
        
        for i in range(N):
            cur = cur + arr[i]
            if cur>maximum:
                maximum = cur
            if cur < 0:
                cur = 0
        return maximum


#{ 
 # Driver Code Starts
#Initial Template for Python 3

import math

 
def main():
        T=int(input())
        while(T>0):
            
            n=int(input())
            
            arr=[int(x) for x in input().strip().split()]
            
            ob=Solution()
            
            print(ob.maxSubArraySum(arr,n))
            
            T-=1


if __name__ == "__main__":
    main()
# } Driver Code Ends
    




# Print the Largest Sum Contiguous Subarray:

# To print the subarray with the maximum sum the idea is to maintain start index 
# of maximum_sum_ending_here at current index so that whenever maximum_sum_so_far is 
# updated with maximum_sum_ending_here then start index and end index of subarray can 
# be updated with start and current index.
    
# // Java program to print largest
# // contiguous array sum
import java.io.*;
import java.util.*;
class GFG {

	static void maxSubArraySum(int a[], int size)
	{
		int max_so_far = Integer.MIN_VALUE,
			max_ending_here = 0, start = 0, end = 0, s = 0;

		for (int i = 0; i < size; i++) {
			max_ending_here += a[i];

			if (max_so_far < max_ending_here) {
				max_so_far = max_ending_here;
				start = s;
				end = i;
			}

			if (max_ending_here < 0) {
				max_ending_here = 0;
				s = i + 1;
			}
		}
		System.out.println("Maximum contiguous sum is "
						+ max_so_far);
		System.out.println("Starting index " + start);
		System.out.println("Ending index " + end);
	}

	# // Driver code
	public static void main(String[] args)
	{
		int a[] = { -2, -3, 4, -1, -2, 1, 5, -3 };
		int n = a.length;
		maxSubArraySum(a, n);
	}
}

# // This code is contributed by prerna saini
