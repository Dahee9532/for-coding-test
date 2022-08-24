#include <bits/stdc++.h>

using namespace std;


int solution(string s) {
    vector<string> vecString[s.size()/2];
    string resultStr[s.size()/2];
    
    int answer = s.size();
    int plus = 0, idx = 0;

    for(int i = 0; i < s.size()/2; i++){
        plus++;
        idx = 0;
        for(int j = 0; idx < s.size(); j++){
            if(idx+plus > s.size()){
                vecString[i].push_back(s.substr(idx));
            }
            else{
                vecString[i].push_back(s.substr(idx, plus));
            }
            idx += plus;
        }
    }  
    int count;
    for(int i = 0; i < s.size()/2; i++){
        count = 1;
        for(int j = 0; j < vecString[i].size(); j++){
            if(vecString[i][j] != vecString[i][j+1] || j == vecString[i].size()-1){
                if(count != 1){
                    resultStr[i] += to_string(count);
                    resultStr[i] += vecString[i][j];
                }
                else{
                    resultStr[i] += vecString[i][j];
                }
                count = 1;
            }
            else{
                count++;
            }
        }
        if(resultStr[i].size() < answer) answer = resultStr[i].size();
    }
    
    return answer;
}
