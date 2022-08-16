#include <bits/stdc++.h>

using namespace std;

int n,k;

int main(void){
    cin >> n >> k;
    int count = 0;

    while(true){
        if(n == 1) break;
        if(n%k == 0) n /= k;
        else n--;
        count++;
    }
    cout << count << '\n';
}
