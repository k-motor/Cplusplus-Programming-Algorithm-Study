#include<bits/stdc++.h>

using namespace std;

int n, m, ret;
int arr[8][8];

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void bfs(){
	queue<int> q;
	int backup[8][8];
	int visited[8][8] = {0,};
	
	for(int x=0; x<n; x++){
		for(int y=0; y<m; y++){
			backup[x][y] = arr[x][y];
			if(backup[x][y] == 2){
				q.push(y*10 + x);
				visited[x][y] = 1;
			}
		}
	}
	
	while(!q.empty()){
		int cur = q.front();
		q.pop();
		
		int nx = cur % 10;
		int ny = cur / 10;
		
		backup[nx][ny] = 2;
		
		for(int dir =0; dir<4; dir++){
			int x = nx + dx[dir];
			int y = ny + dy[dir];
			
			if(x < 0 || x >= n || y <0 || y>=m){
				continue;
			}
			
			if(visited[x][y] ==0 && backup[x][y] == 0){
				visited[x][y] = 1;
				q.push(y*10 + x);
			}
		}
	}
	
	int temp = 0;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(backup[i][j] == 0){
				temp++;
			}
		}
	}
	
	if(ret < temp){
		ret = temp;
	}
}

void pick_dfs(int count, int nx, int ny){
	if(count == 3){
		bfs();
		return;
	}

	for(int x=nx; x<n; x++){
		for(int y=ny; y<m; y++){
			if(arr[x][y] == 0){
				arr[x][y] = 1;
				pick_dfs(count+1, x, y);
				arr[x][y] = 0;
			}
		}
		ny = 0;
	}
}

int main(void){
	cin >> n >> m;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			scanf("%1d", &arr[i][j]);
		}
	}
	
	pick_dfs(0,0,0);
	
	cout << ret << '\n';
	
	return 0;
}
