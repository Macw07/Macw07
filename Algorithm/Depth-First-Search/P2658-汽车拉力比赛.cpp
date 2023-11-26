#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#include <queue>
using namespace std;

int n, m, ll = 0x7f7f7f7f, bb, ii;
int map[505][505];
int vis[505][505];
int block[505][505];
bool flag = false;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

struct node{
    int x, y;
};
node arr[250005];

void dfs(int x, int y, int mid){
    for (int i=0; i<4; i++){
        int cx = x + dx[i];
        int cy = y + dy[i];
        if (cx < 1 || cy < 1 || cx > n || cy > m || vis[cx][cy] || abs(map[x][y] - map[cx][cy]) > mid) continue;
        vis[cx][cy] = 1;
        dfs(cx, cy, mid);
    }
    return ;
}

bool check(){
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            if (block[i][j] == 1 && vis[i][j] != 1) return false;
        }
    }
    return true;
}

int main(){
    cin >> n >> m;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            cin >> map[i][j];
            ll = min(ll, map[i][j]);
            bb = max(bb, map[i][j]);
        }
    }

    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            cin >> block[i][j];
            if (block[i][j]) arr[ii++] = (node){i, j};
        }
    }

    int l = 0, r = bb-ll+1, ans;
    while(l <= r){
        int mid = (l+r) >> 1;
        dfs(arr[0].x, arr[0].y, mid);
        if (check()){
            ans = mid;
            r = mid - 1;
        } else{
            l = mid + 1;
        }
        memset(vis, 0, sizeof vis);
    }
    cout << ans << endl;
    return 0;
}