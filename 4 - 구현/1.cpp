//#include <iostream>
#include <bits/stdc++.h> //표준 라이브러리 헤더들을 한번에 compile될 수 있도록

using namespace std;

// N을 입력받기
int n;
string plans;
int x = 1, y = 1;

// L, R, U, D에 따른 이동 방향 
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
char moveTypes[4] = {'L', 'R', 'U', 'D'};

int main(void) {
    cin >> n;
    cin.ignore(); // 버퍼 비우기 
    getline(cin, plans);

    
    for(int i = 0; i < plans.size() ; i++){
        char plan = plans[i];

        for(int j = 0; j < 4; j++){
            if(plan == moveTypes[j]){
                if(x+dx[j] > 0 && x+dx[j] < n && y+dy[j] > 0 && y+dy[j] < n){
                    x += dx[j];
                    y += dy[j];
                }
            }
        }
    }

    cout << x << ' ' << y << '\n';

}