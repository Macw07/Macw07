#include <iostream>
#include <algorithm>
using namespace std;

// 真的服了这几天了，烧了一天感觉脑子烧坏掉了，低级错误一大堆。

int n, m;
int arr[100005];

int lower(int t){
    int l = 1, r = n, ans = -1;
    while(l <= r){
        int mid = (l+r) >> 1;
        if (arr[mid] >= t){
            r = mid - 1;
            ans = mid;
        } else l = mid + 1;
    }
    return ans;
}

int higher(int t){
    int l = 1, r = n, ans = -1;
    while(l <= r){
        int mid = (l+r) >> 1;
        if (arr[mid] <= t){
            l = mid + 1;
            ans = mid;
        } else r = mid - 1;
    }
    return ans;
}

int main(){
    cin >> n;
    for (int i=1; i<=n; i++){
        cin >> arr[i];
    }
    sort(arr+1, arr+1+n);
    cin >> m;
    for (int i=1; i<=m; i++){
        int t;
        cin >> t;
        int l = lower(t);
        int r = higher(t);
        if (l != -1 && r != -1) cout << (r-l+1) << endl;
        else cout << 0 << endl;
    }
    return 0;
}