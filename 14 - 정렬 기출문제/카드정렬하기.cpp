#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> v;
//문제 : https://www.acmicpc.net/problem/1715

//항상 카드 수가 최소가 되는 카드 묶음끼리 뭉치는 문제
//사이즈가 1 될때까지 다음을 반복
//1. 최소 힙에서 두개를 꺼낸다.
//2. 두 개를 더한 결과를 cnt에 추가한다.
//3. 두 개를 더한 결과를 최소 힙에 push 한다. 
//https://seokjin2.tistory.com/29

int main(void){
    cin >> N;
    priority_queue<int, vector<int>, greater<int> > pq; 
    //priority_queue<int, vector<int>, less<int> > pq; 
    for(int i = 0; i < N; i++){
        int x;
        cin >> x;
        pq.push(x);
    }
    int cnt = 0;
    while(pq.size() != 1){
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        cnt += a + b;
        pq.push(a+b);
    }
    cout << cnt;

    return 0;
}
