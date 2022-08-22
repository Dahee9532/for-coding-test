#include <bits/stdc++.h>

using namespace std;

string str;

int main(void){
    cin >> str;
    int total = int(str[0]-48);
    
    for(int i = 0; i < str.size()-1; i++){
        //cout << int(str[i]-48) << '\n';
        if(int(str[i]-48) == 0 || int(str[i]-48) == 1){
            total += int(str[i+1]-48);
        }
        else total *= int(str[i+1]-48);
    }
    cout << total << '\n';
}


//https://github.com/ndb796/python-for-coding-test/blob/master/11/2.cpp 
