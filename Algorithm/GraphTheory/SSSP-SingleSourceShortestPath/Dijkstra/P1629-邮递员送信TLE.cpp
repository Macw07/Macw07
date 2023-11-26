#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

const int MAXM = 1e5 + 5;
const int MAXN = 1e3 + 5;

int n, m, ei;
struct perEdge{
    int to;
    int next;
    int weight;
} edge[MAXM];
int vertex[MAXN];
int vis[MAXN], dis[MAXN], oto[MAXN];

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
    scanf("%d %d", &n, &m);
    for (int i=1; i<=m; i++){
        int v1, v2, w;
        scanf("%d %d %d", &v1, &v2, &w);
        add(v1, v2, w);
    }
    
    long long total = 0;
    dijkstra(1);
    for (int i=1; i<=n; i++) oto[i] = dis[i];
    for (int i=2; i<=n; i++) {
        total += oto[i];
        memset(vis, 0, sizeof vis);
        dijkstra(i);
        total += dis[1];
    }
    printf("%lld\n", total);
    return 0;
}