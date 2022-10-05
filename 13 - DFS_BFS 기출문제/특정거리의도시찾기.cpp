#include<bits/stdc++.h>

using namespace std;

int N, M, K, X;
int graph[300000][300000];
vector<pair<int, int> > info;

void bfs(int x, int y){
    if(x == y) return ;
    queue<pair<int, int> > q;
    q.push(make_pair(x, y));

    int dist = 1;
    while(!q.empty()){
        dist++;
        q.pop();

        for(int i = 0; i < M; i++){
            if(y == info[i].first){
                if(graph[x-1][info[i].second-1] == 0 || graph[x-1][info[i].second-1] > dist){
                    graph[x-1][info[i].second-1] = dist;
                    graph[info[i].second-1][x-1] = dist;
                }
                else if(graph[x-1][info[i].second-1] != 0 && graph[x-1][info[i].second-1] < dist) continue;
                q.push(make_pair(info[i].first, info[i].second));
            } 
        }
    }
    return ;
}

int main(void){
    cin >> N >> M >> K >> X;

    for(int i = 0; i < M; i++){
        int x;
        int y;
        cin >> x >> y;
        info.push_back(make_pair(x, y));
        graph[x-1][y-1] = 1;
        graph[y-1][x-1] = 1;
    }

    // for(int i = 0; i < N; i++){
    //     for(int j = 0; j < N; j++){
    //         cout << graph[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

    for(int i = 0; i < M; i++){
        bfs(info[i].first, info[i].second);
    }

    // cout << '\n';
    // for(int i = 0; i < N; i++){
    //     for(int j = 0; j < N; j++){
    //         cout << graph[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    bool check = true;
    for(int i = 0; i < N; i++){
        if(graph[X-1][i] == K){
            cout << i+1 << '\n';
            check = false;
        }
    }   
    if(check) cout << "-1" << '\n';

}
