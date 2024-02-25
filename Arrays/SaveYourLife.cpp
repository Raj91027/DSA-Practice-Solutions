
/*Save Your Life
 Given a string w, integer array b,  character array x and an integer n. 
 n is the size of array b and array x. Find a substring which has the sum of 
 the ASCII values of its every character, as maximum. ASCII values of some characters are redefined.
Note: Uppercase & lowercase both will be present in the string w. Array b and Array x contain corresponding
 redefined ASCII values. For each i, b[i] contain redefined ASCII value of character x[i].


Example::
W = abcde
N = 1
X[] = { 'c' }
B[] = { -1000 }
Output:
de
Explanation:
Substring "de" has the
maximum sum of ascii value,
including c decreases the sum value

Expected Time Complexity: O(|W|)
Expected Auxiliary Space: O(1)

Link: https://www.geeksforgeeks.org/problems/save-your-life4601/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article

*/





//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
      string maxSum(string s,char x[], int b[],int n){
          
        unordered_map<char, int> mp;
          for(int i=0; i<n; i++) 
            mp[x[i]] = b[i];
          
          int ans = INT_MIN, curr = 0;
          string temp, res;

          for(int i=0; i<s.length(); i++) {
              if(mp.find(s[i]) != mp.end())
                curr += mp[s[i]];
              else{
                curr += s[i];
              }
              
              temp += s[i];
              if(curr > ans) {
                  ans = curr;
                  res = temp;
              }
              if(curr < 0) {
                  curr = 0;
                  temp = "";
              }
          }
          return res;   
      }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string w;
        cin>>w;
        int n;
        cin>>n;
        char x[n];
        int b[n];
        for(int i = 0;i<n;i++)
            cin>>x[i];
        for(int i = 0;i<n;i++)
            cin>>b[i];
        Solution ob;
        cout << ob.maxSum(w,x,b,n) << endl;
    }
    return 0; 
}
// } Driver Code Ends



/*Another Approach in Python*/



#User function Template for python3


class Solution:
    def maxSum (self, w, x, b, n):
        dc = dict()
        for i in range(n):
            dc[x[i]] = b[i]
        cur = 0
        ans = ""
        temp = ""
        maximum = float('-inf')  # Using negative infinity as the initial maximum value
        
        for i in range(len(w)):
            if w[i] in dc:
                ascii_val = dc[w[i]]
            else:
                ascii_val = ord(w[i])
                
            cur += ascii_val
            temp += w[i]
            
            if cur > maximum:
                maximum = cur
                ans = temp
            if cur < 0:
                cur = 0
                temp = ""
        return ans
            


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__': 
    t = int (input ())
    for _ in range (t):
        w = input()
        n = int(input())
        x = input().split(' ')
        b = input().split(' ')
        for itr in range(n):
            b[itr] = int(b[itr])
       

        ob = Solution()
        print(ob.maxSum(w,x,b,n))
# } Driver Code Ends