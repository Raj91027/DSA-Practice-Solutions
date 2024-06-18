int firstOccurrences(vector<int>& arr, int n, int x){
	int s = 0;
	int e= n-1;
	int ans = -1;
	int mid = s + (e-s)/2;
	while(s<=e){
		if(arr[mid]==x){
			ans = mid;
			e = mid-1;
		}
		else if(arr[mid]<x){
			s = mid+1;
		}
		else{
			e = mid-1;
		}
		mid = s+(e-s)/2;
	}
	return ans;
}

int lastOccurrences(vector<int>& arr, int n, int x){
	int s = 0;
	int e= n-1;
	int ans = -1;
	int mid = s + (e-s)/2;
	while(s<=e){
		if(arr[mid]==x){
			ans = mid;
			s = mid+1;
		}
		else if(arr[mid]<x){
			s = mid+1;
		}
		else{
			e = mid-1;
		}
		mid = s+(e-s)/2;
	}
	return ans;
}
int count(vector<int>& arr, int n, int x) {
	int first = firstOccurrences(arr,n,x);
	int last = lastOccurrences(arr,n,x);

	if(first!=-1 && last!=-1){
		return last-first+1;
	}
	else
		return 0;
}
