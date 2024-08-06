#include<queue>
int signum(int a , int b){
	if(a==b)
		return 0;
	else if(a > b){
		return 1;
	}
	else{
		return -1;
	}
}

void call_median(int ele,priority_queue<int> &maxi,
				priority_queue<int, vector<int>, greater<int> >&mini, int &median){
				
		switch(signum(maxi.size(), mini.size())){

			case 0: if(ele > median){
						mini.push(ele);
						median = mini.top();
			    	}
					else{
						maxi.push(ele);
						median = maxi.top();
					}
					break;
			case 1: if(ele > median){
						mini.push(ele);
						median = (maxi.top() + mini.top())/2;
					}
					else{
						mini.push(maxi.top());
						maxi.pop();
						maxi.push(ele);
						median = (maxi.top() + mini.top())/2;
					}
					break;
			case -1: if(ele > median){
						maxi.push(mini.top());
						mini.pop();
						mini.push(ele);
						median = (maxi.top() + mini.top())/2;
					}
					else{
						maxi.push(ele);
						median = (maxi.top() + mini.top())/2;
					}
		}
}

vector<int> findMedian(vector<int> &arr, int n){
	vector<int> ans;
	priority_queue<int> maxHeap;
	priority_queue<int, vector<int>, greater<int> >minHeap;

	int median = 0;

	for(int i=0; i<n; i++){
		call_median(arr[i], maxHeap,minHeap,median);
		ans.push_back(median);
	}
	return ans;
}
