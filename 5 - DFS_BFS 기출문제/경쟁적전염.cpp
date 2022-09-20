#include <bits/stdc++.h>

using namespace std;

int N, K, S;
int X, Y;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int graph[200][200];
bool visit[200][200];

void dfs(int x, int y){
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || nx >= N || ny  < 0 || ny >= N || visit[nx][ny] || graph[nx][ny] != 0) continue;
        visit[nx][ny] = true;
        graph[nx][ny] = graph[x][y];
    }
}

void visitSetting(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            visit[i][j] = false;
        }
    }
}

int main(void){
    cin >> N >> K; // N x N, 1부터 K까지 바이러스 종류
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> graph[i][j];
        }
    }
    cin >> S >> X >> Y;// 2 3 2 -> 2초 후 (3,2)에 위치하는 바이러스 종류

    // for(int i = 0; i < N; i++){
    //     for(int j = 0; j < N; j++){
    //         cout << graph[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

    for(int i = 0; i < S; i++){
        visitSetting();
        for(int j = 0; j < K; j++){//1부터 적용하기 ~ K까지
            for(int k = 0; k < N; k++){
                for(int l = 0; l < N; l++){
                    if(graph[k][l] == (j+1) && !visit[k][l]) dfs(k, l);
                }
            }
        }
    }
    // cout << '\n';
    // for(int i = 0; i < N; i++){
    //     for(int j = 0; j < N; j++){
    //         cout << graph[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    cout << graph[X-1][Y-1] << '\n';
}
