#include <bits/stdc++.h>

using namespace std;

int n, m, k;
vector<int> v;

int main() {
  // N, M, K를 공백을 기준으로 구분하여 입력 받기
  cin >> n >> m >> k;

  int total=0;
  int count = 0;
  // N개의 수를 공백을 기준으로 구분하여 입력 받기
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    v.push_back(x);
  }

  sort(v.begin(), v.end()); // 입력 받은 수들 정렬하기
  int first = v[n - 1];     // 가장 큰 수
  int second = v[n - 2];    // 두 번째로 큰 수

  for(int j = 0; j < m; j++){
    if(count == k){ //k번 중복되었을때 second 더해주고, count = 0 만들기
      total += second;
      count = 0;
      continue;
    }
    else total += first; 
    count++;
  }
  cout << total << '\n';
}
