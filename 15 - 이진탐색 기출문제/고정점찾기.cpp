#include <bits/stdc++.h>

using namespace std;

int binarySearch(vector<int>& v, int start, int end){
    if(start > end) return -1;
    int mid = (start+end)/2;

    if(v[mid] == mid) return mid;
    else if(v[mid] > mid) return binarySearch(v, start, mid-1);
    else return binarySearch(v, mid+1, end);
}

int n;
vector<int> arr;

int main(void){
    cin >> n;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        arr.push_back(x);
    }
    int result = binarySearch(arr, 0, n-1);
    if(result == -1) cout << -1 << '\n';
    else cout << result << '\n';
}
