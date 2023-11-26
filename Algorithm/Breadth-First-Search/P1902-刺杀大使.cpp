#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

// 题目中出现了最大值最小的字眼，所以这道题可以使用二分的方法来进行解决。

int ans = 0;
int n, m;
int l = 0x7f7f7f7f, r = -0x7f7f7f7f;
int arr[1005][1005];
int vis[1005][1005];
int dx[] = {0, 1, -1, 0};
int dy[] = {1, 0, 0, -1};
struct node{int x, y;};

bool check(int mid){
    queue<node> que;
    que.push((node){1, 1});
    vis[1][1] = 1;
    while(!que.empty()){
        node front = que.front();
        for (int i=0; i<4; i++){
            int cx = front.x + dx[i];
            int cy = front.y + dy[i];
            if (cx < 1 || cy < 1 || cx > n || cy > m || vis[cx][cy] || arr[cx][cy] > mid) continue;
            vis[cx][cy] = 1;
            if (cx == n) return true;
            que.push((node){cx, cy});
        }
        que.pop();
    }
    return false;
}

int main(){
    cin >> n >> m;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            cin >> arr[i][j];
            l = min(l, arr[i][j]);
            r = max(r, arr[i][j]);
        }
    }
    // 二分答案
    while(l <= r){
        int mid = (l+r) >> 1;
        memset(vis, 0, sizeof vis);
        if (check(mid)){
            r = mid - 1;
            ans = mid;
        } else{
            l = mid + 1;
        }
    }
    cout << ans << endl;
    return 0;
}