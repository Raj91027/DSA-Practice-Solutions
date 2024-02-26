
# #Given an array arr[] denoting heights of N towers and a positive integer K.

# For each tower, you must perform exactly one of the following operations exactly once.

# Increase the height of the tower by K
# Decrease the height of the tower by K
# Find out the minimum possible difference between the height of the shortest and tallest towers after you have modified each tower.

# You can find a slight modification of the problem here.
# Note: It is compulsory to increase or decrease the height by K for each tower. After the operation, the resultant array should not contain any negative integers.

# Example 1:

# Input:
# K = 2, N = 4
# Arr[] = {1, 5, 8, 10}
# Output:
# 5
# Explanation:
# The array can be modified as 
# {1+k, 5-k, 8-k, 10-k} = {3, 3, 6, 8}. 
# The difference between 
# the largest and the smallest is 8-3 = 5.


# Expected Time Complexity: O(N*logN)
# Expected Auxiliary Space: O(N)

#Link:https://www.geeksforgeeks.org/problems/minimize-the-heights3351/1


#User function Template for python3

class Solution:
    def getMinDiff(self, arr, n, k):
        arr.sort()
        
        mini = arr[0]
        maxi = arr[n-1]
        
        ans = arr[n-1] - arr[0]
        
        for i in range(n):
            if arr[i] < k:
                continue
            mini = min(arr[0]+k, arr[i]-k)
            
            maxi = max(arr[i - 1]+k, arr[n-1]-k)
            
            ans = min(ans, maxi-mini) 
        
        return ans


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    tc = int(input())
    while tc > 0:
        k = int(input())
        n = int(input())
        arr = list(map(int, input().strip().split()))
        ob = Solution()
        ans = ob.getMinDiff(arr, n, k)
        print(ans)
        tc -= 1

# } Driver Code Ends