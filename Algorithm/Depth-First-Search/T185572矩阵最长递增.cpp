#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int arr[15][15];
int ans = 0;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1 , 0};
int vis[15][15];

void dfs(int x, int y, int length){
    for (int i=0; i<4; i++){
        int cx = x + dx[i];
        int cy = y + dy[i];
        if (vis[cx][cy] == 1) continue;
        if (arr[cx][cy] > arr[x][y]){
            vis[cx][cy] = 1;
            ans = max(ans, length+1);
            dfs(cx, cy, length+1);
            vis[cx][cy] = 0;
        }
    }
}

int main(){
    cin >> n >> m;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            cin >> arr[i][j];
        }
    }
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            dfs(i, j, 1);
        }
    }
    cout << ans << endl;
    return 0;
}