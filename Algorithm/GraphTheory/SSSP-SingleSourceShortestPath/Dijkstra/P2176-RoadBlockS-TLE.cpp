#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

const int MAXM = 5005;
int n, m, ei, ans;
int vis[105], vertex[105], dis[105];

struct perEdge{
    int to;
    int weight;
    int next;
} edge[2*MAXM];

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
    memset(vis, 0, sizeof vis);
    for (int i=1; i<=n; i++){
        dis[i] = 0x7f7f7f7f;
    }
    dis[origin] = 0;
    priority_queue<node> que;
    que.push((node){0, origin});

    while(!que.empty()){
        node t = que.top();
        que.pop();
        if (vis[t.position]) continue;
        vis[t.position] = 1;

        for (int i=vertex[t.position]; i != 0; i = edge[i].next){
            int u = edge[i].to;
            int w = edge[i].weight;
            if (dis[t.position] + w < dis[u]){
                dis[u] = dis[t.position] + w;
                que.push((node){dis[u], u});
            }
        }
    }
    return ;
}

int main(){
    scanf("%d %d", &n, &m);
    for (int i=1; i<=m; i++){
        int v1, v2, w;
        scanf("%d %d %d", &v1, &v2, &w);
        add(v1, v2, w);
        add(v2, v1, w);
    }
    dijkstra(1);
    int t_ans = dis[n];
    int ans = 0;
    for (int i=1; i<=2*m; i+=2){
        edge[i].weight *= 2;
        edge[i+1].weight *= 2;
        ans = max(ans, dis[n] - t_ans);
        dijkstra(1);
        edge[i].weight /= 2;
        edge[i+1].weight /= 2;
    }
    printf("%d\n", ans);
    return 0;
}