#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> arr;

int main(void){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        arr.push_back(x);
    }
    int start = 0;
    int end = 1e9;
    int result = 0;

    while(start <= end){
        long long int total = 0;
        int mid = (start+end)/2;

        for(int i = 0; i < n; i++){//잘랐을 때 떡의 양 계산
            if(arr[i] > mid) total += arr[i] - mid;
            //mid가 더 크면 잘린 떡 길이는 0cm
        }

        if(total < m) end = mid - 1;//떡의 양이 m값에 못 미칠때. 절단기 높이 줄여야함
        else{//떡의 양이 m보다 클때. 절단기 최댓값 찾아야하니깐.
            result = mid;//result 기록.
            start = mid + 1;
        }
    }
    cout << result << '\n';
}
