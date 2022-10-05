#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> num;

bool compare(int a, int b){
    return a > b;
}

int main(void){
    cin >> N;
    for(int i = 0; i < N; i++){
        int x;
        cin >> x;
        num.push_back(x);
    }
    sort(num.begin(), num.end(), compare);

    for(int i = 0; i < N; i++){
        cout << num[i] << ' ';
    }
}
