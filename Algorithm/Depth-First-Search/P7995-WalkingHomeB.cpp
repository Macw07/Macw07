#include <iostream>
#include <algorithm>
using namespace std;

int t, n, k, ans;
char map[55][55];
int dx[] = {0, 1, 0};
int dy[] = {0, 0, 1};

void dfs(int x, int y, int dir, int tt){
    if (tt > k) return ;
    if (x == n && y == n){
        ans += 1;
        return ;
    }
    if (x != n && y != n && tt == k) return ;
    for (int i=1; i<=2; i++){
        int cx = x + dx[i];
        int cy = y + dy[i];
        if (cx > n || cy > n || cx < 1 || cy < 1) continue;
        if (map[cx][cy] == 'H') continue;
        dfs(cx, cy, i, tt + (dir != -1 && dir != i));
    }

    return ;
}

int main(){
    cin >> t;
    while(t--){
        ans = 0;
        cin >> n >> k;
        for (int i=1; i<=n; i++){
            for (int j=1; j<=n; j++){
                cin >> map[i][j];
            }
        }
        dfs(1, 1, -1, 0);
        cout << ans << endl;
    }
    return 0;
}