#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

const int MAXN = 1e6;

struct node1{int to, next, w; };
struct node2{
    int distance, position;
    // 优先队列排序
    bool friend operator < (node2 a, node2 b){
        return a.distance > b.distance;
    }
};

node1 edge[MAXN];
int head = 0;
int n, m, s;
int vis[MAXN];
int ans[MAXN];
int vertex[MAXN];

void add(int v1, int v2, int w){
    head += 1;
    edge[head].to = v2;
    edge[head].next = vertex[v1];
    edge[head].w = w;
    vertex[v1] = head;
    return ;
}

void dijsktra(int origin){
    for (int i=1; i<=n; i++) ans[i] = 2147483647;
    ans[origin] = 0;
    priority_queue<node2> que;
    que.push((node2){0, origin});
    while(!que.empty()){
        node2 t = que.top();
        que.pop();
        if (vis[t.position]) continue;  // 已经访问过了，不需要再次访问
        vis[t.position] = 1;
        int index = vertex[t.position];
        while(index != -1){
            int u = edge[index].to;
            int w = edge[index].w;
            if (ans[t.position] + w < ans[u]){
                ans[u] = ans[t.position] + w;
                que.push((node2){ans[u], u});
            }
            index = edge[index].next;
        }   
    }
    return ;
}

int main(){
    memset(vertex, -1, sizeof vertex);
    scanf("%d %d %d", &n, &m, &s);
    for (int i=1; i<=m; i++){
        int v1, v2, w;
        scanf("%d %d %d", &v1, &v2, &w);
        add(v1, v2, w);
    }
    dijsktra(s);
    for (int i=1; i<=n; i++) printf("%d ", ans[i]);
    return 0;
}