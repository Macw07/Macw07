#include <iostream>
#include <vector>
using namespace std;

int m, n;
int sx, sy, fx, fy, k=0;
int arr[25][25];
int vis[25][25];
int sum[50005][2];
int dx[] = {0, -1, 0, 1};
int dy[] = {-1, 0, 1, 0};
bool flag = 0;

void dfs(int x, int y){
    if (x == fx && y == fy){
        flag = 1;
        for (int i=0; i<k; i++){
            printf("(%d,%d)->",sum[i][0], sum[i][1]);
        }
        printf("(%d,%d)\n",fx, fy);
        return;
    }
    for (int i=0; i<4; i++){
        int cx = x + dx[i];
        int cy = y + dy[i];
        if (vis[cx][cy] == 1 || arr[cx][cy] == 0) continue;
        vis[x][y] = 1;
        sum[k][0] = x;
        sum[k][1] = y;
        k++;
        dfs(cx, cy);
        vis[x][y] = 0;
        k--;
    }
    return;
}

int main(){
    cin >> n >> m;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            cin >> arr[i][j];
        }
    }
    cin >> sx >> sy >> fx >> fy;
    dfs(sx, sy);
    if (flag == 0){
        cout << -1 << endl;
    }
    return 0;
}