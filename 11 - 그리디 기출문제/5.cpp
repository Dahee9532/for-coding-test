//5 3
//1 2 2 3 3 
// 5-1 = 4 (나머지 값), 1x4 = 4
// 4-2 = 2 (나머지 값), 2x2 = 4
// 2-2 = 0 (나머지 값), 3x0 = 0 
#include <bits/stdc++.h>
using namespace std;

int n,m;
int arr[11];

int main(void){
    cin >> n >> m;
    
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        arr[x] += 1;
    }

    int result = 0;

    for(int i = 1; i <= m; i++){
        n -= arr[i];
        result += n * arr[i];
    }
    cout << result << '\n';
}
