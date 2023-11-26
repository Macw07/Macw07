#include <iostream>
#include <algorithm>
using namespace std;

char arr[55][55];
int vis[55][55];
int n, m;  // n, m代表长和宽也代表终点的坐标
int ans=0x7f7f7f;  // ans 表示最小的路径
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

// 通过深度优先搜索来判定
void dfs(int x, int y, int step){
    if (x == n && y == m){
        ans = min(ans, step);  // 更新结果
        return;
    }
    // 顺时针遍历每一个点
    for (int i=0; i<4; i++){
        int cx = x+dx[i], cy = y+dy[i];
        if (vis[cx][cy] == 0 && arr[cx][cy] == '.'){  // 没有被访问
            vis[cx][cy] = 1;  // 标记已访问
            dfs(cx, cy, step+1);  // 递归调用
            vis[cx][cy] = 0;  // 清除状态
        }
    }
    return;
}

int main(){
    cin >> n >> m;
    for (int i=1; i<=n; i++){
        string s;
        cin >> s;
        for (int j=1; j<=m; j++){
            arr[i][j] = s[j-1];
        }
    }
    // 标记起点为已访问
    vis[1][1] = 1;
    dfs(1, 1, 0);
    if (ans != 0x7f7f7f){
        // cout << ans << endl;
        cout << "YES" << endl;
    } else{
        cout << "NO" << endl;
    }
    return 0;   
}