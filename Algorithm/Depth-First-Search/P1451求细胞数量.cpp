#include <iostream>
using namespace std;

int n, m;
int arr[105][105];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int vis[105][105];
int ans = 0;

void dfs(int x, int y){
    vis[x][y] = 1;
    for (int i=0; i<4; i++){
        int cx = x + dx[i];
        int cy = y + dy[i];
        if (cx > n || cy > m || vis[cx][cy] == 1 || arr[cx][cy] == 0) continue;
        dfs(cx, cy);
    }
}

int main(){
    cin >> n >> m;
    for (int i=1; i<=n; i++){
        string s;
        cin >> s;
        for (int j=1; j<=m; j++){
            arr[i][j] = s[j-1]-'0';
        }
    }
    int ans = 0;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            if (arr[i][j] != 0 && vis[i][j] == 0){
                ans++;
                dfs(i, j);
            }
        }
    }
    cout << ans << endl;
    return 0;
}