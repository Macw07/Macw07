#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int n, m, ans;
int G[25][25];
int vis[25];

void dfs(int vertex, int weight){
    ans = max(weight, ans);
    for (int i=1; i<=n; i++){
        if (G[vertex][i] == -1) continue;
        if (vis[i] == 0){
            vis[i] = 1;
            dfs(i, weight + G[vertex][i]);
            vis[i] = 0;
        }
    }
    return ;
}

int main(){
    cin >> n >> m;
    memset(G, -1, sizeof G);
    for (int i=1; i<=m; i++){
        int v1, v2, w;
        cin >> v1 >> v2 >> w;
        G[v1][v2] = G[v2][v1] = w;
    }
    // 从起点i出发搜索到的最大结果。
    for(int i=1; i<=n; i++){
        memset(vis, 0, sizeof vis);
        vis[i] = 1;
        dfs(i, 0);
    }
    cout << ans << endl;
    return 0;
}