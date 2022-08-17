#include <bits/stdc++.h>

using namespace std;

string str;

int main(void){
    cin >> str;
    int zeroCount = 0; //zero 그룹 수
    int oneCount = 0; //one 그룹 수

    if(str[0] == '0') zeroCount++; 
    else oneCount++;
//10101 => 2
//0001100 => 1

    //바뀔 때 마다 카운트. 1로 바뀌면 1 카운트. 
    for(int i = 0; i < str.size()-1; i++){
        if(str[i] != str[i+1]){
            if(str[i+1] == '1') oneCount++;
            else zeroCount++;
        }
    }
    cout << min(zeroCount, oneCount) << '\n'; // 그룹이 더 적은 것 선택
} 

//https://github.com/ndb796/python-for-coding-test/blob/master/11/3.cpp
