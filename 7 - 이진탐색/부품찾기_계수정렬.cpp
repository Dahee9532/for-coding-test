#include <bits/stdc++.h>

using namespace std;

// N : 가게의 부품 개수
// M : 손님이 확인 요청한 부품 개수
int n, m;
int arr[100001];
vector<int> targets;

int main(void){
    cin >> n;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        arr[x] = 1;
    }
    cin >> m;
    for(int i = 0; i < m; i++){
        int target;
        cin >> target;
        targets.push_back(target);
    }
    for(int i = 0; i < m; i++){
        if(arr[targets[i]] == 1) cout << "yes" << ' ';
        else cout << "no" << ' ';
    }
}
