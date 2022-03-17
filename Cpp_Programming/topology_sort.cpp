#include<bits/stdc++.h>

#define MAX 10

using namespace std;

int n, indegree[MAX];
vector<int> a[MAX];

void topologySort(){
	int result[MAX];
	queue<int> q;
	
	for(int i=1; i<=n; i++){
		if(indegree[i] == 0){
			q.push(i);
		}
	}
	
	for(int i=1; i<=n; i++){
		if(q.empty()){
			cout << "cycle\n"; 
			return;
		}
		
		int x = q.front();
		q.pop();
		
		result[i] = x;
		for(int i=0; i<a[x].size();i++){
			int y = a[x][i];

			
			if(--indegree[y] == 0){
				q.push(y);
			}
		}	
	}
	
	for(int i=1; i<=n; i++){
		printf("%d ", result[i]);
	}	
}

int main(void){
	n = 7;
	a[1].push_back(2);
	indegree[2]++;
	a[1].push_back(5);
	indegree[5]++;
	a[2].push_back(3);
	indegree[3]++;
	a[3].push_back(4);
	indegree[4]++;
	a[4].push_back(6);
	indegree[6]++;
	a[5].push_back(6);
	indegree[6]++;
	a[6].push_back(7);
	indegree[7]++;
	topologySort();
}
