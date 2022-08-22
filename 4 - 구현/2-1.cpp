#include <bits/stdc++.h>

using namespace std;

int n;

int main(void){
    cin >> n;
    int count = 0;

    for(int i = 0; i <= n; i++){
        for(int j = 0; j < 60; j++){
            for(int k = 0; k < 60; k++){
                if(to_string(k).find('3') != string::npos || to_string(j).find('3') != string::npos || to_string(i).find('3') != string::npos) count++;
            }
        }
    }

    cout << count << '\n';
}   

#https://github.com/ndb796/python-for-coding-test/blob/master/4/2.cpp
