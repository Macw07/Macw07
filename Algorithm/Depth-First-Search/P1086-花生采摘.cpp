#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int arr[25][25];
int vis[25][25];
int n, m, k, ans;

struct coordinate{int x, y;};
coordinate begin_first;

coordinate check(){
    // 找到最大的一株花生，返回花生的最大价值
    int x=0, y=0, amount=0;
    for (int i=1; i<=n; i++){;
        for (int j=1; j<=m; j++){
            if (!vis[i][j] && arr[i][j] > amount){
                amount = arr[i][j];
                x = i, y = j;
            }
        }
    }
    vis[x][y] = 1;
    return (coordinate){x, y};
}   

void dfs(int x, int y, int nx, int ny, int amount, int steps){
    // 判断是否来得及
    int go = abs(nx-x) + abs(ny-y);
    int times = go + nx + 1;
    if (times+steps > k) return ;  // 回不去了
    coordinate next = check();
    ans = max(ans, amount + arr[nx][ny]);
    dfs(nx, ny, next.x, next.y, amount + arr[nx][ny], steps + times - nx);
}

int main(){
    cin >> n >> m >> k;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            cin >> arr[i][j];
        }
    }
    begin_first = check();
    dfs(0, begin_first.y, begin_first.x, begin_first.y, 0, 0);
    cout << ans << endl;
    return 0;
}