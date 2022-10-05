#include<bits/stdc++.h>

using namespace std;

int n, k;
vector<int> aArray;
vector<int> bArray;

bool compare(int a, int b){
    return a > b;
}

int main(void){
    cin >> n >> k;

    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        aArray.push_back(x);
    }

    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        bArray.push_back(x);
    }
    sort(aArray.begin(), aArray.end());
    sort(bArray.begin(), bArray.end(), compare);

    for(int i = 0; i < k; i++){
        if(aArray[i] < bArray[i]) swap(aArray[i], bArray[i]);
        else break;
    }

    long long result = 0;
    for(int i = 0; i < n; i++){
        result += aArray[i];
    }
    cout << result << '\n';
}
