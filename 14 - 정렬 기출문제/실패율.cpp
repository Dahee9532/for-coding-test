#include <bits/stdc++.h>

using namespace std;

bool compare(pair<int, double>a, pair<int, double>b){
    if(a.second == b.second) return a.first < b.first;
    return a.second > b.second;
}

int record[500];
vector<pair<int, double>> recordVal;

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    int totalUser = stages.size();
    int curUser = 0;
    
    for(int i = 0; i < stages.size(); i++){
        if(stages[i] > N) continue;
        record[stages[i]-1]++;
    }

    for(int i = 0; i < N; i++){
        if(record[i] == 0){ //해당 if문 추가해줄필요가 있는듯. 0 != 0/5 (?)
            recordVal.push_back({i+1, 0});
            continue;
        }
        recordVal.push_back({i+1,(double)record[i]/(totalUser-curUser)});
        curUser += record[i];
    }
    sort(recordVal.begin(), recordVal.end(), compare);
    for(int i = 0; i < recordVal.size(); i++){
        answer.push_back(recordVal[i].first);
    }
    
    
    return answer;
}


//https://school.programmers.co.kr/learn/courses/30/lessons/42889?language=cpp
