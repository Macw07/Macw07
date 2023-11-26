#include <iostream>
#include <algorithm>
using namespace std;

int n, m, ans = 0;
char arr[15][15];
bool vis[15][15];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

void dfs(int x, int y){
    if (x == n && y == m){
        ans++;
        return ;
    }
    for (int i=0; i<4; i++){
        int cx = x + dx[i];
        int cy = y + dy[i];
        if (cx < 1 || cy < 1 || cx > n || cy > m || vis[cx][cy] || arr[cx][cy] == '#') continue;
        vis[cx][cy] = 1;
        dfs(cx, cy);
        vis[cx][cy] = 0;
    }
    return ;
}

int main(){
    cin >> n >> m;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            cin >> arr[i][j];
        }
    }
    vis[1][1] = 1;
    dfs(1, 1);
    cout << ans << endl;
    return 0;
}