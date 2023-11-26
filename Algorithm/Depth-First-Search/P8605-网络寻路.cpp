#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int n, m, ei, ans;
int vertex[10005];
int vis[10005];
int temp[5];
struct perEdge{
    int to;
    int next;
} edge[200005];

void add(int v1, int v2){
    ei += 1;
    edge[ei].to = v2;
    edge[ei].next = vertex[v1];
    vertex[v1] = ei;
    return ;
}

void dfs(int b, int v, int steps){
    if (steps == 3){
        ans += 1;
        return ;
    }
    int index = vertex[v];
    while(index != 0){
        int to = edge[index].to;
        if (vis[to] == 0){
            // cout << steps << endl;
            vis[to] = 1;
            dfs(b, to, steps + 1);
            vis[to] = 0;
        }
        if (steps == 2 && to == b){
            dfs(b, to, steps + 1);
        }
        index = edge[index].next;
    }
    return ;
}

int main(){
    cin >> n >> m;
    for (int i=1; i<=m; i++){
        int v1, v2;
        cin >> v1 >> v2;
        add(v1, v2);
        add(v2, v1);
    }
    for (int i=1; i<=n; i++){
        // 对每一个点都进行搜索，搜索2步。
        memset(vis, 0, sizeof vis);
        vis[i] = 1;
        dfs(i, i, 0);
    }
    cout << ans << endl;
    return 0;
}

// 1 2 3 1
// 1 3 2 1
// 2 3 1 2
// 2 1 3 2
// 3 1 2 3
// 3 2 1 3