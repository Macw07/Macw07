#include <iostream>
using namespace std;

int n, ans = 0x7f7f7f7f;
int vis[20];  // 表示每个任务是否被占用了。
int arr[25][25];

void dfs(int dep, int cost){
    if (dep > n){
        ans = min(ans, cost);
        return ;
    }
    if (cost > ans) return ;  // 最优性减枝操作。

    for (int i=1; i<=n; i++){
        // 判断这个任务是否被占用了。
        if (vis[i] == 1) continue;
        vis[i] = 1;
        // 让第dep只蚂蚁做第i件任务。
        dfs(dep+1, cost + arr[dep][i]);
        vis[i] = 0;
    }
    return ;
}

int main(){
    cin >> n;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            cin >> arr[i][j];  // 表示第i只蚂蚁完成第j项任务所需要的花费。
        }
    }
    dfs(1, 0);  // 从第i只蚂蚁开始递归，初始话费为0。
    cout << ans << endl;
    return 0;
}