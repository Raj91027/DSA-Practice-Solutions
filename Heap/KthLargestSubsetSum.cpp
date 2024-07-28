//Approach-1: Using array of subset sum

#include<algorithm>
int getKthLargest(vector<int> &arr, int k)
{
	int n = arr.size();
	vector<int> subSet;
	for(int i=0; i<n; i++){
		int sum = 0;

		for(int j=i; j<n; j++){
			sum+=arr[j];
			subSet.push_back(sum);
		}
	}

	sort(subSet.begin(), subSet.end());

	return subSet[subSet.size()-k];
}

// Approach-2: Using mini Heap

#include<queue>
int getKthLargest(vector<int> &arr, int k)
{
	priority_queue<int, vector<int>, greater<int> > mini;

	int n = arr.size();
	for(int i=0; i<n; i++){
		int sum = 0;

		for(int j=i; j<n; j++){
			sum += arr[j];

			if(mini.size() < k){
				mini.push(sum);
			}
			else{
				if(sum > mini.top()){
					mini.pop();
					mini.push(sum);
				}
			}
		}
	}
	return mini.top();
}