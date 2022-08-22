#include<bits/stdc++.h>

using namespace std;

string str;

int dx[8] = {-1, 1, 2, 2, 1, -1, -2, -2};
int dy[8] = {-2, -2, -1, 1, 2, 2, 1, -1};


int main(void){
    cin >> str;

    int cnt = 0;

    int x = str[0] - 96;
    int y = str[1] - 48;
    for(int i = 0; i < 8; i++){
        if(x+dx[i] > 0 && x+dx[i] < 9 && y+dy[i] > 0 && y+dy[i] < 9) cnt++;
    }

    cout << cnt << '\n';

    return 0;

}
