
#include <bits/stdc++.h>

using namespace std;

int N;
int graph[25][25];
bool visit[25][25];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int ret = 0;
vector<int> info;

int dfs(int x, int y){
	visit[x][y] = true;
	for(int i = 0; i < 4; i++){
		int nx = x+dx[i];
		int ny = y+dy[i];
		if(nx < 0 || nx >= N || ny < 0 || ny >= N || visit[nx][ny] || graph[nx][ny] == 0) continue;
		ret ++;
		dfs(nx, ny);
	}
	return ret;
}



int main(){
  cin >> N;

  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      scanf("%1d", &graph[i][j]);
    }
  }

  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
		if(visit[i][j] || graph[i][j] == 0) continue;
		ret = 1;
		info.push_back(dfs(i,j));
    }
  }
  cout << info.size() << '\n';
  for(int i = 0; i < info.size(); i++){
	  cout << info[i] << '\n';
  }
}
