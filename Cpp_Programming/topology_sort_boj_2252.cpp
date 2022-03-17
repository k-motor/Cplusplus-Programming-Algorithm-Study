#include<bits/stdc++.h>

#define MAX 32001
using namespace std;

int n, indegree[MAX], result[MAX];
vector<int> a[MAX];

void topologySort(){
	queue<int> q;
	
	for(int i=1; i<=n; i++){
		if(indegree[i] == 0){
			q.push(i);
		}
	}
	
	for(int i=1; i<=n; i++){
		int x = q.front();
		q.pop();
		
		result[i] = x;
		for(int i=0; i<a[x].size(); i++){
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
	int m;
	cin >> n >> m;
	for(int i=0; i<m; i++){
		int x, y;
		scanf("%d %d", &x, &y);
		a[x].push_back(y);
		indegree[y]++;
	}
	
	topologySort();
}
