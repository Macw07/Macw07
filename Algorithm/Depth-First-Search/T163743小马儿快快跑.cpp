#include <iostream>
#include <cstring>
using namespace std;

int n, m, p, q;
int arr[15][15];
int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
int vis[15][15];
int ans[15][15];

void dfs(int x, int y){
    for (int i=0; i<8; i++){
        int cx = x+dx[i];
        int cy = y+dy[i];
        if (cx > n || cy > n || cy < 1 || cx < 1 || vis[cx][cy]) continue;
        vis[cx][cy] = 1;
        ans[cx][cy] = min(ans[cx][cy], ans[x][y]+1);
        dfs(cx, cy);
        vis[cx][cy] = 0;
    }
    return;
}

int main(){
    cin >> n >> m;
    cin >> p >> q;
    memset(ans,0x7f,sizeof(ans));
    ans[p][q] = 0;
    dfs(p, q);
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            if (ans[i][j] == 0x7f7f7f7f){
                printf("%-5d",-1);
            } else{
                printf("%-5d",ans[i][j]);
            }
        }
        cout << endl;
    }
    return 0;
}