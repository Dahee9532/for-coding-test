#include<bits/stdc++.h>

using namespace std;

int N, M;
int ori_graph[8][8];
int graph[8][8];
vector<pair<int, int> > zero;
int maxCount;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

//2이면 queue에 push, 그리고 주변이 0이면 2로 바꾸기 
void bfs(int x, int y){
    queue<pair<int, int> > q;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(graph[i][j] == 2) q.push(make_pair(i, j));//그래프에서 2이면 큐에 push
        }
    }

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if(graph[nx][ny] == 0){//0일때 2로 바꾸고 좌표를 큐에 push
                graph[nx][ny] = 2;
                q.push(make_pair(nx, ny));
            }
        }
    }
}

void copy(int ori_graph[8][8], int graph[8][8]){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            graph[i][j] = ori_graph[i][j];
        }
    }
}

int countArea(int graph[8][8]){
    int total = 0;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(graph[i][j] == 0) total++;
        }
    }
    return total;
}
 
int main(void){
    cin >> N >> M;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            scanf("%1d", &ori_graph[i][j]);
            if(ori_graph[i][j] == 0){
                zero.push_back(make_pair(i, j));
            }
        }
    }
 
    for(int i = 0; i < zero.size()-3; i++){
        for(int j = i+1; j < zero.size(); j++){
            for(int k = j+1; k < zero.size(); k++){
                copy(ori_graph, graph);
                graph[zero[i].first][zero[i].second] = 1;
                graph[zero[j].first][zero[j].second] = 1;
                graph[zero[k].first][zero[k].second] = 1;
                bfs(0, 0);
                int result = countArea(graph);
                if(result > maxCount) maxCount = result;
            }
        }
    }
    cout << maxCount << '\n';
}
