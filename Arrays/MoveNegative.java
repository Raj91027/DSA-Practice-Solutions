/*Move all negative elements to end

 * Solution of DSA Sheet by Love Babar 
 * Code written by: Raj Kumar Yadav
 */

 /*
  * Given an unsorted array arr[] of size n having both negative and positive integers. 
   The task is place all negative element at the end of array without changing the order 
   of positive element and negative element.
  */

  /*
   * Example 1:

    Input : 
    n = 8
    arr[] = {1, -1, 3, 2, -7, -5, 11, 6 }
    Output : 
    1  3  2  11  6  -1  -7  -5
   */

   //Link: https://www.geeksforgeeks.org/problems/move-all-negative-elements-to-end1813/1


   //Solution ....

   //{ Driver Code Starts
//Initial Template for Java

import java.util.*;
import java.lang.*;
import java.io.*;

class GFG {
	public static void main(String[] args) throws IOException
	{
	        BufferedReader br =
            new BufferedReader(new InputStreamReader(System.in));
            PrintWriter ot = new  PrintWriter(System.out);
        int t =
            Integer.parseInt(br.readLine().trim()); // Inputting the testcases
        while(t-->0)
        {
            int n = Integer.parseInt(br.readLine().trim());
            int a[] = new int[(int)(n)];
            String inputLine[] = br.readLine().trim().split(" ");
            for (int i = 0; i < n; i++) {
                a[i] = Integer.parseInt(inputLine[i]);
            }
            
            Solution obj = new Solution();
            obj.segregateElements(a, n);
            
            for(int i=0;i<n;i++)
            ot.print(a[i]+" ");
            
            ot.println();
        }
        ot.close();
	}
}

// } Driver Code Ends


//User function Template for Java

class Solution {
    
    public void segregateElements(int arr[], int n)
    {
        int b[] = new int[n];
        int j=0;
        for(int i=0;i<n;i++){
            if(arr[i]>=0){
                b[j]=arr[i];
                j++;
            }
        }
        
        for(int i=0;i<n;i++){
            if(arr[i]<0){
                b[j]=arr[i];
                j++;
            }
        }
        
        for(int i=0;i<n;i++){
            arr[i]=b[i];
        }
        
    }

}