class Solution {
  public:

    void rearrange(vector<int> &arr) {
        vector<int> negArr;
        vector<int> posArr;
        
        for(int i=0; i<arr.size(); i++){
            if(arr[i] < 0){
                negArr.push_back(arr[i]);
            }
            else{
                posArr.push_back(arr[i]);
            }
        }
        int i=0;
        int pos=0;
        int neg=0;
        while(i< arr.size()){
            if(pos<posArr.size())
                arr[i++]=posArr[pos++];
            if(neg < negArr.size())
                arr[i++] = negArr[neg++];
        }
    }
};