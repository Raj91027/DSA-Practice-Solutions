class Solution {
  public:
    pair<long long, long long> getMinMax(vector<long long int> arr) {
        long long mini = INT_MAX;
        long long maxi = INT_MIN;
        
        for(long long i=0; i<arr.size(); i++){
            mini = min(arr[i], mini);
            maxi = max(arr[i],maxi);
        }
        
        pair<long long, long  long> ans;
        ans.first = mini;
        ans.second = maxi;
        
        return ans;
    }
};