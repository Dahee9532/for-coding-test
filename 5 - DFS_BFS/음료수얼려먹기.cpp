#include <bits/stdc++.h>

using namespace std;

int N, M;
int graph[1000][1000];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

bool dfs(int x, int y){

    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < 0 || nx >= N || ny < 0 || ny >= M || graph[nx][ny] == 1) continue;
        graph[nx][ny] = 1;
        dfs(nx, ny);
        return true;
    }
    return false;
}

int main(void){
    cin >> N >> M;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            scanf("%1d", &graph[i][j]);
        }
    }
    
    int cnt = 0;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(dfs(i, j)) cnt++;
        }
    }
    cout << cnt << '\n';
}
