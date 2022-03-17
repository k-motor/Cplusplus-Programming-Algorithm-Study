#include<bits/stdc++.h>

#define MAX 501

using namespace std;

int n, indegree[MAX], t[MAX], result[MAX];
vector<int> a[MAX];

void topologySort(){
	queue<int> q;
	
	for(int i=1; i<=n; i++){
		if(indegree[i] == 0){
			result[i] = t[i];
			q.push(i);
		}
	}
	
	for(int i=1; i<=n; i++){
		int x = q.front();
		q.pop();
		
		for(int i=0; i<a[x].size(); i++){
			int y = a[x][i];
			
			result[y] = max(result[y], result[x] + t[y]);
			
			if(--indegree[y] == 0){
				q.push(y);
			}
		}
	}
	
	for(int i=1; i<=n;i++){
		printf("%d\n", result[i]);
	}
}

int main(void){
	cin >> n;
	
	for(int i=1; i<=n; i++){
		scanf("%d", &t[i]);
		while(1){
			int x;
			scanf("%d", &x);
			if(x == -1) break;
			indegree[i]++;
			a[x].push_back(i);
		}
	}
	
	topologySort();
}
