#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

// 这是可以忍的吗：小于号写成了大于号

int n, m, k, ans;
int arr[505][505];
int vis[505][505];
int qaq[505][505][15];
int dx[] = {0, 1, -1, 0};
int dy[] = {1, 0, 0, -1};

int dfs(int x, int y, int ki){
    if (qaq[x][y][ki]) return qaq[x][y][ki];
    int sum = 1;
    for (int i=0; i<4; i++){
        int cx = x + dx[i];
        int cy = y + dy[i];
        if (cx < 1 || cy < 1 || cx > n || cy > m) continue;
        if (arr[cx][cy] > arr[x][y]) sum = max(sum, dfs(cx, cy, ki) + 1);
        else if (ki < k) sum = max(sum, dfs(cx, cy, ki+1) + 1);
        qaq[x][y][ki] = sum;
    }
    return qaq[x][y][ki];
}

int main(){
    cin >> n >> m >> k;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            cin >> arr[i][j];
        }
    }
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            ans = max(ans, dfs(i, j, 0));
        }
    } 
    cout << ans << endl;
    return 0;
}