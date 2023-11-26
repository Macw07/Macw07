#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

const int MAXM = 1e5 + 5;
const int MAXN = 1e3 + 5;

int n, m, ei, ei_r;
struct perEdge1{
    int to;
    int next;
    int weight;
} edge[MAXM];
struct perEdge2{
    int to;
    int next;
    int weight;
} edge_r[MAXM];
int vertex[MAXN];
int vertex_r[MAXN];
int vis[MAXN], dis[MAXN];
int vis_r[MAXN], dis_r[MAXN];

struct node{
    int distance;
    int position;
    bool friend operator < (node a, node b){
        return a.distance > b.distance;
    };
};

void add(int v1, int v2, int weight){
    ei += 1;
    edge[ei].to = v2;
    edge[ei].weight = weight;
    edge[ei].next = vertex[v1];
    vertex[v1] = ei;
    return ;
}

void add_r(int v1, int v2, int weight){
    ei_r += 1;
    edge_r[ei_r].to = v2;
    edge_r[ei_r].weight = weight;
    edge_r[ei_r].next = vertex_r[v1];
    vertex_r[v1] = ei_r;
    return ;
}

void dijkstra(int origin){
    memset(dis, 0x7f, sizeof dis);
    dis[origin] = 0;
    priority_queue<node> que;
    que.push((node){0, origin});

    while(!que.empty()){
        node t = que.top();
        que.pop();
        if (vis[t.position]) continue;
        vis[t.position] = 1;

        int index = vertex[t.position];
        while(index != -1){
            int u = edge[index].to;
            int w = edge[index].weight;
            if (t.distance + w < dis[u]){
                dis[u] = t.distance + w;
                que.push((node){dis[u], u});
            }
            index = edge[index].next;
        }
    }
    return ;
}

void dijkstra_r(int origin){
    memset(dis_r, 0x7f, sizeof dis_r);
    dis_r[origin] = 0;
    priority_queue<node> que;
    que.push((node){0, origin});

    while(!que.empty()){
        node t = que.top();
        que.pop();
        if (vis_r[t.position]) continue;
        vis_r[t.position] = 1;

        int index = vertex_r[t.position];
        while(index != -1){
            int u = edge_r[index].to;
            int w = edge_r[index].weight;
            if (t.distance + w < dis_r[u]){
                dis_r[u] = t.distance + w;
                que.push((node){dis_r[u], u});
            }
            index = edge_r[index].next;
        }
    }
    return ;
}

int main(){
    memset(vertex, -1, sizeof vertex);
    memset(vertex_r, -1, sizeof vertex_r);
    scanf("%d %d", &n, &m);
    for (int i=1; i<=m; i++){
        int v1, v2, w;
        scanf("%d %d %d", &v1, &v2, &w);
        add(v1, v2, w);
        add_r(v2, v1, w);  // 反向建图目的：求有向图其他顶点到源点的最短路，以源点再跑一遍dij算法即可。
    }
    
    long long total = 0;
    dijkstra(1);
    for (int i=1; i<=n; i++) total += dis[i];
    dijkstra_r(1);
    for (int i=1; i<=n; i++) total += dis_r[i];
    printf("%lld\n", total);
    return 0;
}