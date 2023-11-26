#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

const int MAXM = 1e5+5;
const int MAXN = 1e3+5;

int n, m, x, ei, ei_;
struct perEdge{
    int to;
    int next;
    int weight;
};
struct node{
    int distance;
    int position;
    bool friend operator < (node a, node b){
        return a.distance > b.distance;
    };
};
perEdge edge[MAXM], edge_[MAXM];
int vertex[MAXN], vertex_[MAXN];
int vis[MAXN], vis_[MAXN];
int dist[MAXN], dist_[MAXN];

void add(int v1, int v2, int weight){
    ei += 1;
    edge[ei].to = v2;
    edge[ei].weight = weight;
    edge[ei].next = vertex[v1];
    vertex[v1] = ei;
    return ;
}

void add_(int v1, int v2, int weight){
    ei_ += 1;
    edge_[ei].to = v2;
    edge_[ei].weight = weight;
    edge_[ei].next = vertex_[v1];
    vertex_[v1] = ei_;
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
        if (vis[t.position]) continue;
        vis[t.position] = 1;

        int index = vertex[t.position];
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

void dijkstra_(int origin){
    memset(dist_, 0x7f, sizeof dist_);
    dist_[origin] = 0;
    priority_queue<node> que;
    que.push((node){0, origin});

    while(!que.empty()){
        node t = que.top();
        que.pop();
        if (vis_[t.position]) continue;
        vis_[t.position] = 1;

        int index = vertex_[t.position];
        while(index != -1){
            int u = edge_[index].to;
            int w = edge_[index].weight;
            if (t.distance + w < dist_[u]){
                dist_[u] = t.distance + w;
                que.push((node){dist_[u], u});
            }
            index = edge_[index].next;
        }
    }
    return ;
}

int main(){
    scanf("%d %d %d", &n, &m, &x);
    memset(vertex, -1, sizeof vertex);
    memset(vertex_, -1, sizeof vertex_);
    for (int i=1; i<=m; i++){
        int v1, v2, w;
        scanf("%d %d %d", &v1, &v2, &w);
        add(v1, v2, w);
        add_(v2, v1, w);
    }

    int ans = 0;
    dijkstra(x);
    dijkstra_(x);
    for (int i=1; i<=n; i++) ans = max(ans, dist[i] + dist_[i]);
    cout << ans << endl;
    return 0;
}