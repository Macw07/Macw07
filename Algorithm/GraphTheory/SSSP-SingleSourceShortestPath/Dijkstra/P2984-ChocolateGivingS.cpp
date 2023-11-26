#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

const int MAXM  = 100000 + 5;
const int MAXN = 50000 + 5;
int n, m, b, ei;
int vertex[MAXN], dis[MAXN], vis[MAXN];
struct perEdge{
    int to;
    int next;
    int weight;
} edge[MAXM * 2];

void add(int v1, int v2, int weight){
    ei += 1;
    edge[ei].to = v2;
    edge[ei].next = vertex[v1];
    edge[ei].weight = weight;
    vertex[v1] = ei;
    return ;    
}

struct node{
    int distance;
    int position;
    bool friend operator < (node a, node b){
        return a.distance > b.distance;
    };
};

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

int main(){
    memset(vertex, -1, sizeof vertex);
    scanf("%d %d %d", &n, &m, &b);
    for (int i=1; i<=m; i++){
        int v1, v2, w;
        scanf("%d %d %d", &v1, &v2, &w);
        add(v1, v2, w);
        add(v2, v1, w);
    }
    dijkstra(1);
    for (int i=1; i<=b; i++){
        int t1, t2;
        scanf("%d %d", &t1, &t2);
        printf("%d\n", dis[t1] + dis[t2]);
    }
    return 0;
}