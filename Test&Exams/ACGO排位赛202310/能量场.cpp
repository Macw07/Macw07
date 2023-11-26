/*
4 5 6
...*.
...*.
.....
.....
1 3 1 5

4 5 8
...*.
...*.
.....
.....
1 3 1 5
*/

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int n, m, t, ans;
int r1, c1, r2, c2;
char arr[205][205];
int vis[205][205];
int dx[] = {0, 1, -1, 0};
int dy[] = {1, 0, 0, -1};

int distance(int a, int b, int c, int d){
    return abs(a - c) + abs(b - d);
}

void dfs(int x, int y, int steps){
    if (steps > t) return;
    if (distance(x, y, r2, c2) > t) return ;
    if (x == r2 && y == c2 && steps == t){
        ans += 1;
        ans %= 998244353;
        return ;
    }
    for (int i=0; i<4; i++){
        int cx = x + dx[i];
        int cy = y + dy[i];
        if (cx < 1 || cy < 1 || cx > n || cy > m) continue;
        if (arr[cx][cy] == '*') continue;
        dfs(cx, cy, steps + 1);
    }
    return ;
}

int main(){
    cin >> n >> m >> t;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            cin >> arr[i][j];
        }
    }
    cin >> r1 >> c1 >> r2 >> c2;
    dfs(r1, c1, 0);
    cout << ans % 998244353 << endl;
    return 0;
}