#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 100005;

int t, n, id;
int v1, v2, cnt;
int ei, vertex[MAXN];
int vis[10005];
struct perEdge{
    int to;
    int next;
} edges[MAXN << 1];

void add(int v1, int v2){
    ei += 1;
    edges[ei].to = v2;
    edges[ei].next = vertex[v1];
    vertex[v1] = ei;
    return ;
}

void dfs(int root){
    int index = vertex[root];
    while(index != 0){
        int to = edges[index].to;
        if (!vis[to]) {
            vis[to] = 1;
            cnt += 1;
            dfs(to);
        }
        index = edges[index].next;
    }
    return ;
}

int main(){
    scanf("%d", &t);
    for (int i=1; i<=t; i++){
        ei = 0; cnt = 0;
        memset(vis, 0, sizeof vis);
        memset(vertex, 0, sizeof vertex);
        scanf("%d %d", &n, &id);

        for (int j=1; j<=n; j++){
            scanf("%d %d", &v1, &v2);
            add(v2, v1);
        }

        vis[id] = 1;
        dfs(id);  // 判断图的连通性
        printf("Case #%d: %d\n", i, cnt);
    }
    return 0;
}