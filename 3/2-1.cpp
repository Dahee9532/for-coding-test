#include <bits/stdc++.h>
using namespace std;

int n, m, k;
vector<int> v;

int main(void){
    cin >> n >> m >> k;

    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        v.push_back(x);
    }

    sort(v.begin(), v.end());
    int first = v[n-1];
    int second = v[n-2];
    int total = 0;
    //가장 큰 수가 더해지는 횟수 계산
    int count = (m/(k+1))*k;
    count += m%(k+1); 
    total += count * first;
    total += (m-count)*second;//두번째로 큰  수 더하기 

    cout << total << '\n';

}
