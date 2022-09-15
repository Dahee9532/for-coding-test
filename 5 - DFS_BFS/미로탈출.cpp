#include<bits/stdc++.h>

using namespace std;

int N, M;
int graph[200][200];
bool visit[200][200];

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int bfs(int x, int y){
    queue<pair<int, int> > q;
    q.push(make_pair(x, y));
    visit[x][y] = true;

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || nx >= N || ny < 0 || ny >= M || graph[nx][ny] == 0 || visit[nx][ny]) continue;
            visit[nx][ny] = true;
            graph[nx][ny] = graph[x][y] + 1;
            q.push(make_pair(nx, ny));
        }
    }
    return graph[N-1][M-1];
}

int main(void){
    cin >> N >> M;
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            scanf("%1d", &graph[i][j]);
        }
    }

    cout << bfs(0, 0) << '\n';
    
}
