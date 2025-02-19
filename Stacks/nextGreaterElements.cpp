


class Solution {
    public:
      // Function to find the next greater element for each element of the array.
      vector<int> nextLargerElement(vector<int>& arr) {
          int n = arr.size();
          stack<int> s;
          //s.push(-1);
          vector<int> ans(n,-1);
      
          for(int i = n-1; i>=0; i--){
              int curr = arr[i];
              while(!s.empty() && s.top() <= curr){
                  s.pop();
              }
              
              if(!s.empty()){
              ans[i] = s.top();
              
              }
              s.push(curr);
          }
      
          return ans;
              
          
      }
  };