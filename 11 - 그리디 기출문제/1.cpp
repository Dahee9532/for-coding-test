#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> v;

int main(void){
    cin >> n;

    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end()); //오름차순 정렬

    int count = 0; // 현재 그룹에 포함된 모험가의 수
    int total = 0; //그룹 수 

    for(int i = 0; i < n; i++){ 
        count++;
        if(count >= v[i]){ //사람 수가 공포도보다 크거나 같으면 그룹 수 증가. 
            total++;
            count = 0;
        }
    }
    cout << total << '\n';
}