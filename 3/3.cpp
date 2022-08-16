#include <bits/stdc++.h>

using namespace std;

int n,m;

int main(void){
    cin >> n >> m;
    vector<int> v[n];

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int x;
            cin >> x;
            v[i].push_back(x);
        }
        sort(v[i].begin(), v[i].end());
    }

    int max = v[0][0];
    for(int k = 0; k < n; k++){
        if(max < v[k][0]) max = v[k][0];
    }
    cout << max << '\n';
}
