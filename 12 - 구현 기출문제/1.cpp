#include <bits/stdc++.h>

using namespace std;

string n;

int main(void){
    cin >> n;
    int pre = 0;
    int post = 0;
    int loc = 1;

    for(int i = 0; i < n.size(); i++){
        if((i+1) > n.size()/2) loc = 2;
        if(loc == 1) pre += n[i];
        else post += n[i];
    }

    if(pre == post) cout << "LUCKY" << '\n';
    else cout << "READY" << '\n';

    return 0;

}