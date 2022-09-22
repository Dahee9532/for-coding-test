#include <bits/stdc++.h>

using namespace std;

int N, K, S, X, Y;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int graph[200][200];

struct Virus{
    int val;
    int x;
    int y;
};

bool cmp(Virus& v1, Virus& v2){
    return v1.val < v2.val;
}

int main(void){
    cin >> N >> K;
    vector<Virus> vec;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> graph[i][j];
            if(graph[i][j] >= 1 && graph[i][j] <= K) vec.push_back({graph[i][j], i, j});
        }
    }
    cin >> S >> X >> Y;
    sort(vec.begin(), vec.end(), cmp);
    int s = 0;

    while(s < S){
        int len = vec.size();
        for(int i = 0; i < len; i++){
          Virus v = vec[i];
            for(int j = 0; j < 4; j++){
                int nx = v.x + dx[j];
                int ny = v.y + dy[j];
                if(nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
                if(!graph[nx][ny]){
                    graph[nx][ny] = v.val;
                    vec.push_back({graph[nx][ny], nx, ny});
                }
            }
        }
        if(graph[X-1][Y-1] > 0) break;
        s++;
    }
    cout << graph[X-1][Y-1] << '\n';

}

//https://iot624.tistory.com/147 
