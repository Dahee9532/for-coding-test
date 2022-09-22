#include <bits/stdc++.h>

using namespace std;

bool checkCorrect(string input){
    int len = input.length();
    stack<char> st;
    for(int i = 0; i < len; i++){
        if(input[i] == '(') st.push('(');
        else if(input[i] == ')'){
            if(st.size() == 0) return false;
            st.pop();
        }
    }
    if(st.size() > 0) return false;
    
    return true;
}

string solution(string p) {
    string answer = "";
    // 1. 입력이 빈 문자열인 경우, 빈 문자열을 반환합니다. 
    if(p == "") return p;
    // 2. 문자열 w를 두 "균형잡힌 괄호 문자열" u, v로 분리합니다. 단, u는 "균형잡힌 괄호 문자열"로 더 이상 분리할 수 없어야 하며, v는 빈 문자열이 될 수 있습니다. 
    string u, v;
    int left = 0, right = 0;
    for(int i = 0; i < p.length(); i++){
        if(p[i] == '(') left++;
        else if(p[i] == ')') right++;
        
        if(left == right){
            u = p.substr(0, i+1);
            v = p.substr(i+1);
            break;
        }
    }
    
    // 3. 문자열 u가 "올바른 괄호 문자열" 이라면 문자열 v에 대해 1단계부터 다시 수행합니다. 
    if(checkCorrect(u)){
        v = solution(v);
        //   3-1. 수행한 결과 문자열을 u에 이어 붙인 후 반환합니다. 
        answer = u + v;
        return answer;
    }
    // 4. 문자열 u가 "올바른 괄호 문자열"이 아니라면 아래 과정을 수행합니다. 
    else{
        //   4-1. 빈 문자열에 첫 번째 문자로 '('를 붙입니다. 
        answer = "(";
        //   4-2. 문자열 v에 대해 1단계부터 재귀적으로 수행한 결과 문자열을 이어 붙입니다. 
        answer = answer + solution(v);
        //   4-3. ')'를 다시 붙입니다. 
        answer = answer + ")";
        //   4-4. u의 첫 번째와 마지막 문자를 제거하고, 나머지 문자열의 괄호 방향을 뒤집어서 뒤에 붙입니다. 
        u.erase(0, 1);
        u.erase(u.length()-1, 1);
        for(int i = 0; i < u.length(); i++){
            if(u[i] == '(') u[i] = ')';
            else u[i] = '(';
        }
        answer = answer + u;
        //   4-5. 생성된 문자열을 반환합니다.
        return answer;
    }
}


//https://hochoon-dev.tistory.com/entry/%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%A8%B8%EC%8A%A4-%EA%B4%84%ED%98%B8-%EB%B3%80%ED%99%98-C
//프로그래머스 : https://school.programmers.co.kr/learn/courses/30/lessons/60058
