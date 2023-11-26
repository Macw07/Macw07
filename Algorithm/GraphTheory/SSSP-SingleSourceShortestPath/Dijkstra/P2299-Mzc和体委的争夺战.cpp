#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>

// 这道题死掉的原因，竟然是因为memset，数组开得太大了。

using namespace std;
const int MAXN = 5e5 + 50;

struct node{
    int to;
    int next;
    int weight;
} edge[MAXN];  // 因为是双向建边，所以要开两倍

struct node2{
    int weight, position;
    bool friend operator < (node2 a, node2 b){
        return a.weight > b.weight;
    }
};

int n, m, a, b, c;
int vertex[2550], ei = 1;
int ans[2550], vis[2550];

void add(int v1, int v2, int weight){
    ei += 1;
    edge[ei].to = v2;
    edge[ei].next = vertex[v1];
    edge[ei].weight = weight;
    vertex[v1] = ei;
    return ;
}

void dijkstra(int origin){
    for (int i=1; i<=n; i++) ans[i] = 0x7f7f7f7f;
    ans[origin] = 0;
    priority_queue<node2> que;
    que.push((node2){0, origin});
    while(!que.empty()){
        node2 t = que.top();
        que.pop();
        if (vis[t.position]) continue;
        vis[t.position] = 1;
        int index = vertex[t.position];
        while (index != -1){
            int u = edge[index].to;
            int w = edge[index].weight;
            if (ans[t.position] + w < ans[u]){
                // cout << ans[t.position] + w << endl;
                ans[u] = ans[t.position] + w;
                que.push((node2){ans[u], u});
            }
            index = edge[index].next;
        }
    }
    return ;
}

int main(){
    scanf("%d %d", &n, &m);
    memset(vertex, -1, sizeof vertex);
    for (int i=1; i<=m; i++){
        scanf("%d %d %d", &a, &b, &c);
        add(a, b, c), add(b, a, c);
    }
    dijkstra(1);
    cout << ans[n] << endl;
    return 0;
}