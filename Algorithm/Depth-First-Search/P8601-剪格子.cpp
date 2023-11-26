#include <iostream>
#include <algorithm>
using namespace std;

/*
这的会很悲伤，搞半天一个超级大问题就是n和m写反了
*/

int n, m, sum;
int map[15][15], vis[15][15];
int ans;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void dfs(int x, int y, int nows, int grid){
    if (nows == sum) {
        ans = grid;
        return ;
    }
    if (nows > sum) return ;
    for (int i=0; i<4; i++){
        int cx = x + dx[i];
        int cy = y + dy[i];
        if (cx < 0 || cy < 0 || cx >= n || cy >= m || vis[cx][cy]) continue;
        vis[cx][cy] = 1;
        dfs(cx, cy, nows+map[cx][cy], grid+1);
        if (ans) return ;
        vis[cx][cy] = 0;
    }
    return ;
}

int main(){
    cin >> m >> n;
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            cin >> map[i][j];
            sum += map[i][j];
        }
    }
    if (sum % 2 == 1){
        cout << 0 << endl;
        return 0;
    }
    sum /= 2;
    dfs(0, 0, map[0][0], 1);
    cout << ans << endl;   
    return 0;
}