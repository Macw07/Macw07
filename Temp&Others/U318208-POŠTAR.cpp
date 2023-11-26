#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <cmath>
using namespace std;

struct coordinate{
    int x;
    int y;
};
int max_, min_ = 0x7f7f7f7f, res = 0x7f7f7f7f;
int n, l, r, ans, total;
char map[55][55];
int arr[55][55];
int vis[55][55];
int dx[] = {1, 0, -1, 0, 1, 1, -1, -1};
int dy[] = {0, 1, 0, -1, -1, 1, -1, 1};
coordinate start;

// 思路：枚举最小值，这样子就可以确定最大值了。

bool check(int low, int mid){  // 最低高度为low，最高高度为mid。
    memset(vis, 0, sizeof vis);
    vis[start.x][start.y] = 1;
    int cnt = 0;
    queue<coordinate> que;
    que.push((coordinate){start.x, start.y});

    while(!que.empty()){
        coordinate t = que.front();
        que.pop();
        if (cnt == total) return true;
        for (int i=0; i<8; i++){
            int cx = t.x + dx[i];
            int cy = t.y + dy[i];
            if (cx < 1 || cy < 1 || cx > n || cy > n || vis[cx][cy]) continue;
            if (arr[cx][cy] > mid || arr[cx][cy] < low) continue;
            if (map[cx][cy] == 'K') cnt ++;
            vis[cx][cy] = 1;
            que.push((coordinate){cx, cy});
        }
    }
    return false;
}

int main(){
    cin >> n;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            cin >> map[i][j];
            if (map[i][j] == 'P') start = (coordinate){i, j};
            else if (map[i][j] == 'K') total += 1;
        }
    }
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            cin >> arr[i][j];
            max_ = max(max_, arr[i][j]);
        }
    }
    // 枚举最小值，让走完路的最大值最小。
    for (int i=0; i<=max_; i++){
        l = i, r = max_;
        ans = 0x7f7f7f7f;
        while(l <= r){
            int mid = (l+r) >> 1;
            if (check(i, mid)){
                ans = mid;
                r = mid - 1;
            } else l = mid + 1; 
        }
        if (ans == 0x7f7f7f7f) break;
        res = min(res, ans - i);
    }
    cout << res << endl;
    return 0;
}