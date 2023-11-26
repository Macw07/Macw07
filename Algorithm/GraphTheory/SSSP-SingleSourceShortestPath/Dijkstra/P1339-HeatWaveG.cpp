#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

const int MAXM = 12500;

int n, m, s, t;
struct peredge{
    int to;
    int next;
    int weight;
} edge[MAXM];
int vertex[3000], dist[3000], ei, vis[3000];

struct node{
    int distance;
    int vertex_p;
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

void dijkstra(int origin){
    memset(dist, 0x7f, sizeof dist);
    dist[origin] = 0;
    priority_queue<node> que;
    que.push((node){0, origin});

    while(!que.empty()){
        node t = que.top();
        que.pop();
        if (vis[t.vertex_p]) continue;
        vis[t.vertex_p] = 1;

        int index = vertex[t.vertex_p];
        while(index != -1){
            int u = edge[index].to;
            int w = edge[index].weight;
            if (t.distance + w < dist[u]){
                dist[u] = t.distance + w;
                que.push((node){dist[u], u});
            }
            index = edge[index].next;
        }
    }
    return ;
}

int main(){
    memset(vertex, -1, sizeof vertex);
    scanf("%d %d %d %d", &n, &m, &s, &t);
    for (int i=1; i<=m; i++){
        int v1, v2, w;
        scanf("%d %d %d", &v1, &v2, &w);
        add(v1, v2, w);
        add(v2, v1, w);
    }
    dijkstra(s);
    printf("%d\n", dist[t]);
    return 0;
}