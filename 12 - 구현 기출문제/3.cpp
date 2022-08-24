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
                vecString[i].push_back(s.substr(idx));//idx부터 끝까지 모든 문자 포함
            }
            else{
                vecString[i].push_back(s.substr(idx, plus));//idx부터 plus개의 문자 포함
            }
            idx += plus;//plus 만큼 idx 점프
        }
    }  
    //여기까지 vecString 완성. 이제부터 최소 숫자 구하기
    int count;
    for(int i = 0; i < s.size()/2; i++){
        count = 1;
        for(int j = 0; j < vecString[i].size(); j++){
            if(vecString[i][j] != vecString[i][j+1] || j == vecString[i].size()-1){//다르거나 마지막일때 string 추가
                if(count != 1){//1일때는 생략
                    resultStr[i] += to_string(count);
                    resultStr[i] += vecString[i][j];
                }
                else{
                    resultStr[i] += vecString[i][j];
                }
                count = 1;
            }
            else{//같으면 count 증가
                count++;
            }
        }
        if(resultStr[i].size() < answer) answer = resultStr[i].size();
    }
    
    return answer;
}
