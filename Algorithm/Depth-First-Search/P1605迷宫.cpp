#include <iostream>
using namespace std;

int ans = 0;
int n, m, t;
int sx, sy, fx, fy;
int arr[15][15];
int vis[15][15];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

void dfs(int x, int y){
    if (x == fx && y == fy){
        ans++;
        return;
    }
    for (int i=0; i<4; i++){
        int cx = x + dx[i];
        int cy = y + dy[i];
        if (cx < 1 || cy < 1 || cx > n || cy > m) continue;
        if (vis[cx][cy] || arr[cx][cy]==-1) continue;
        vis[cx][cy] = 1;
        dfs(cx, cy);
        vis[cx][cy] = 0; 
    }
    return;
}

int main(){
    cin >> n >> m >> t;
    cin >> sx >> sy >> fx >> fy;
    for (int i=1; i<=t; i++){
        int x, y;
        cin >> x >> y;
        arr[x][y] = -1;
    }
    vis[sx][sy] = -1;  // 最开始需要将初始地点给标记了
    dfs(sx, sy);
    cout << ans << endl;
    return 0;
}