#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

long long ans;
bool flag;
int n, v1, v2, ei;
int colors[100005];
int vertex[100005];
int vis[100005];
struct perEdge{
    int to;
    int next;
} edges[100005 * 2];

void add(int v1, int v2){
    ei += 1;
    edges[ei].to = v2;
    edges[ei].next = vertex[v1];
    vertex[v1] = ei;
    return ;
}

void dfs(int start, int color, int steps, int original){
    if (vis[start]) return ;
    vis[start] = steps;
    if (start > original && colors[start] == color) ans += steps;
    int index = vertex[start];
    while(index != 0){
        int to = edges[index].to;
        if (colors[to] == color) dfs(to, color, steps + 1, original);
        else dfs(to, color, steps, original);
        index = edges[index].next;
    }
    return ;
}

int main(){
    scanf("%d", &n);
    for (int i=1; i<=n; i++) scanf("%d", &colors[i]);
    for (int i=1; i<n; i++){
        scanf("%d %d", &v1, &v2);
        add(v1, v2);
        add(v2, v1);
    }
    for (int i=1; i<=n; i++){
        memset(vis, 0, sizeof vis);
        // 从i点出发遍历整一棵树，并记录下来。
        dfs(i, colors[i], 1, i);
    }
    cout << ans << endl;
    return 0;
}