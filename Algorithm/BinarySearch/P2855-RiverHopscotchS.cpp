#include <iostream>
#include <algorithm>
using namespace std;

int L, n, m;
int l, r, ans;
int arr[50005];

// 当距离最小为m的时候要取走多少石子。
bool check(int mid){
    int cnt = 0;
    int last = 0;
    for (int i=1; i<=n+1; i++){
        if (arr[i] - last < mid){
            cnt += 1;
        } else last = arr[i];
    }
    return cnt <= m;
}

int main(){
    cin >> L >> n >> m;
    for (int i=1; i<=n; i++) cin >> arr[i];
    sort(arr+1, arr+1+n);
    arr[n+1] = L;

    l = 0, r = L;
    while(l <= r){
        int mid = (l + r) >> 1;
        if (check(mid)){
            l = mid + 1;
            ans = mid;
        } else r = mid - 1;
    }
    cout << ans << endl;
    return 0;
}