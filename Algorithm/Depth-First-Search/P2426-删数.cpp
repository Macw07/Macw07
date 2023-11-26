#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int n;
int arr[1005], max_ = 0;
int vis[1005][1005];

void dfs1(int l, int r, int weight){
    if (l <= r){
        // 从左往右 [l, i] + 取最左边单个
        for (int i=l+1; i<=r; i++) dfs1(i+1, r, weight + abs(arr[l]-arr[i])*(i-l+1));
        dfs1(l+1, r, weight + arr[l]);

        // 从右往左 + 取最右边单个
        for (int i=r-1; i>=l; i--) dfs1(l, i-1, weight + abs(arr[r]-arr[i])*(r-i+1));
        dfs1(l, r-1, weight + arr[r]);
    }
    max_ = max(max_, weight);
    return ;
}

int dfs2(int l, int r){
    if (vis[l][r]) return vis[l][r];

    if (l <= r){
        // 从左往右 [l, i] + 取最左边单个
        int p1=0, p2=0, p3=0, p4=0;

        for (int i=l+1; i<=r; i++) p1 = max(p1, dfs2(i+1, r) + abs(arr[l]-arr[i])*(i-l+1));
        p2 = dfs2(l+1, r) + arr[l];

        // 从右往左 + 取最右边单个
        for (int i=r-1; i>=l; i--) p3 = max(p3, dfs2(l, i-1) + abs(arr[r]-arr[i])*(r-i+1));
        p4 = dfs2(l, r-1)  + arr[r];
        vis[l][r] = max(max(p1, p2), max(p3, p4));
    }
    return vis[l][r];
}

int main(){
    cin >> n;
    for (int i=1; i<=n; i++) cin >> arr[i];
    // dfs1(1, n, 0);
    // cout << max_ << endl;
    cout << dfs2(1, n);
    return 0;
}