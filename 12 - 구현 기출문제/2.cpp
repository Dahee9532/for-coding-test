#include<bits/stdc++.h>

using namespace std;

string str;
//a - 1 = 96 -> a는 97
//A - 1 = 64 -> A는 65
//1 - 1 = 48 -> 1은 49
int main(void){
    cin >> str;
    string str2;
    int total = 0;
    
    for(int i = 0;i < str.size(); i++){
        if(str[i] < 64) total += str[i] - '0';
        else str2 += str[i];
    }

    sort(str2.begin(), str2.end());
    cout << str2 << total << '\n';

    return 0;
}

//https://github.com/ndb796/python-for-coding-test/blob/master/12/2.cpp
//vector<char> result;
//         if (isalpha(str[i])) { 
//             result.push_back(str[i]);
//         }
//숫자 존재하는지 아닌지 체크해야함
