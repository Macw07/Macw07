#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int total = 0;
char arr[105][105];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
char check[] = {'L', 'Q', 'B', 'S'};
bool vis[105][105];

void dfs(int x, int y, int crt){
    if (arr[x][y] == 'S') total++;
    if (crt == 3) crt = -1; 
    for (int i=0; i<4; i++){
        int cx = x + dx[i];
        int cy = y + dy[i];
        if (cx < 1 || cy < 1 || cx > n || cy > m) continue;
        if (arr[x][y] == 'S' && arr[cx][cy] == 'L' && vis[cx][cy] == 1){
            cout << -1 << endl;
            exit(0);
        }
        if (vis[cx][cy]) continue;
        if (arr[cx][cy] == check[crt+1]){
            vis[cx][cy] = 1;
            dfs(cx, cy, crt+1);
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
            if (arr[i][j] == 'L'){
                vis[i][j] = 1;
                dfs(i, j, 0);
            }
        }
    }
    cout << total << endl;
    return 0;
}