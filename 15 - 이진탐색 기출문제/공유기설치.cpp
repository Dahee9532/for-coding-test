#include <bits/stdc++.h>

using namespace std;

int n, c;
vector<int> arr;

// Start = 1
// End = 8
// Mid = 4
// Val = 1

// 2 >= 1+4 X
// 4 >= 1+4 X
// 8 >= 1+4 O -> val = 8, cnt = 2
// 9 >= 8+4 X

// End = mid - 1 = 3
// —————————
// Mid = 1+3 / 2 = 2
// Val = 1

// 2 >= 1+2 X
// 4 >= 1+2 O -> val = 4, cnt = 2
// 8 >= 4+2 O -> val = 8, cnt = 3
// 9 >= 8+2 X 

// Start = 3
// Result = 2
// —————————
// End = 3
// Mid = 3+3 / 2 = 3
// Val = 1

// 2 >= 1+3 X
// 4 >= 1+3 O -> val = 4, cnt = 2
// 8 >= 4+3 O -> val = 8, cnt = 3
// 9 >= 8+3 X

// Start = 4
// Result = 3

int main(){
    cin >> n >> c;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        arr.push_back(x);
    }
    sort(arr.begin(), arr.end());

    int start = 1;
    int end = arr[n-1] - arr[0];
    int result = 0;

    while(start <= end){
        int mid = (start + end)/2;
        int value = arr[0];
        int cnt = 1;

        for(int i = 1; i < n; i++){
            if(arr[i] >= value + mid){
                value = arr[i];
                cnt += 1;
            }
        }

        if(cnt >= c){
            start = mid + 1;
            result = mid;
        }
        else{
            end = mid - 1;
        }
    }
    cout << result << '\n';
}

