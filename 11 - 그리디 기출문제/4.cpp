#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> arr;

int main(void) {
    cin >> n;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        arr.push_back(x);
    }

    sort(arr.begin(), arr.end());

    int target = 1; //누적값
    for (int i = 0; i < n; i++) {
        // 만들 수 없는 금액을 찾았을 때 반복 종료
        if (target < arr[i]) break; //arr는 화폐단위
        target += arr[i];
        cout << target << ' ' ;
    }

    cout << " : " << target << '\n';
}

// ##### greedy TIP!!
// 1. 최솟값을 구하는 문제는 무조건 for문을 돌릴게 아니라, 오름 차순으로 두고 작은 것부터 비교해가면서 풀어야한다.
// 2. 누적합과 화폐단위를 비교해가면서 구해본다. 화폐단위가 누적합 보다 클 경우, 그 사이에 갭이 존재한다는 뜻이다.

// 누적합을 for문으로 차근차근 구해나가면서, 숫자 1부터 비교해 나간다는 것이 포인트였다. 
// 누적합보다 화폐단위가 클 경우에 그 사이에 만들 수 없는 수가 존재한다는 뜻임을 항상 기억하고 다음 그리디 문제에서는 꼭 적용해서 풀어봐야겠다.
// https://didu-story.tistory.com/58
