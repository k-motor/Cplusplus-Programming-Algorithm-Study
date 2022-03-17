#include<bits/stdc++.h>

using namespace std;

int n, m;
vector<int> arr;

int bSearch(vector<int>& arr, int target, int start, int end){
	int sum = 0;
	
	while(start <= end){
		
		int mid = (start+end)/2;
		
		for(int i=0; i<n;i++){
			if(arr[i] > mid){
				sum += arr[i] - mid;	
			}
		}

		if(sum == target){
			return mid;
		}
		else if(sum < target){
			end = mid -1;
		}else{
			start = mid + 1;
		}
		
		sum = 0;
	}
	
	return -1;
}

int main(void){
	cin >> n >> m;
	
	for(int i =0; i<n; i++){
		int x;
		cin >> x;
		arr.push_back(x);
	}
	
	sort(arr.begin(),arr.end());
	
	int result = bSearch(arr, m, 0, arr[n-1]);
	
	printf("%d ", result);
}
