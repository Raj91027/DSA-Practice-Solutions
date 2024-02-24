/*Sort an array of 0s, 1s, 2s.
 * Solution of DSA Sheet by Love Babar 
 * Code written by: Raj Kumar Yadav
 * 
 * 
 * Given an array of size N containing only 0s, 1s, and 2s;
 *  sort the array in ascending order.
 * Example 1:

    Input: 
    N = 5
    arr[]= {0 2 1 2 0}
    Output:
    0 0 1 2 2
    Explanation:
    0s 1s and 2s are segregated 
    into ascending order.
 * 
 * Link :https://www.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s4231/1
 * 
 * 
 */


 //{ Driver Code Starts
//Initial template for Java

import java.io.*;
import java.util.*;


// } Driver Code Ends
//User function template for Java

class Solution
{
    public static void sort012(int a[], int n)
    {
        int l = 0;
        int m = 0;
        int h = n-1;
        int temp=0;
        
        while(m<=h){
            switch(a[m]){
                
                case 0: {
                    temp = a[l];
                    a[l]=a[m];
                    a[m]=temp;
                    l++;
                    m++;
                    break;
                }
                case 1: {
                    m++;
                    break;
                    
                }
                case 2: {
                    temp = a[m];
                    a[m] = a[h];
                    a[h] = temp;
                    h--;
                    break;
                }
            }
        }
        
    }
}

//{ Driver Code Starts.

class Sort012 {
    
    public static void main (String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine().trim()); //Inputting the testcases
        while(t-->0){
            int n = Integer.parseInt(br.readLine().trim());
            int arr[] = new int[n];
            String inputLine[] = br.readLine().trim().split(" ");
            for(int i=0; i<n; i++){
                arr[i] = Integer.parseInt(inputLine[i]);
            }
            Solution ob=new Solution();
            ob.sort012(arr, n);
            StringBuffer str = new StringBuffer();
            for(int i=0; i<n; i++){
                str.append(arr[i]+" ");
            }
            System.out.println(str);
        }
    }
}


// } Driver Code Ends


/*Another Efficient Approach by counting number of 0s, 1s, and 2s.
 * Then store all the 0s at the beginning followed by all the 1s and then all the 2s.
 */
// This code is in C Programming , it is most efficient approach.

//{ Driver Code Starts
//Initial Template for C

#include <stdio.h>


// } Driver Code Ends
//User function Template for C

void sort012(int a[], int n)
{
    int c0=0,c1=0,c2=0;
    int i;
    for(i=0;i<n;i++)
    {
        switch(a[i])
        {
           case 0: c0++;
                   break;
                   
            case 1: c1++;
                    break;
            
            case 2: c2++;
                    break;
            
        }
    }
    i=0;
    while(c0>0){
        a[i++]=0;
        c0--;
    }
    while(c1>0){
        a[i++] = 1;
        c1--;
    }
    
    while(c2>0){
        a[i++]=2;
        c2--;
    }
    
    
    
    
}

//{ Driver Code Starts.

int main() {

    int t;
    scanf("%d", &t);

    while(t--){
        int n;
        scanf("%d", &n);
        int arr[n];
        for(int i=0;i<n;i++){
            scanf("%d", &arr[i]);
        }

        sort012(arr, n);

        for (int i = 0; i < n; i++)
            printf("%d ", arr[i]);
        printf("\n");
    }
    return 0;
}

// } Driver Code Ends
