#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

const int M = 100000 + 5;
const int N = 2000 + 5;

int n, m, ei;
int s, e;
struct perEdge{
    int to;
    int next;
    double weight;
} edge[2*M];
int vertex[N], vis[N];
double dis[N];

struct node{
    double distance;
    int position;
    bool friend operator < (node a, node b){
        return a.distance < b.distance;
    };
};

void add(int v1, int v2, int weight){
    ei += 1;
    edge[ei].to = v2;
    edge[ei].weight = 1.0 - weight/100.0;
    edge[ei].next = vertex[v1];
    vertex[v1] = ei;
    return ;
}

void dijkstra(int origin){
    for (int i=1; i<=n; i++) dis[i] = 0;
    dis[origin] = 1.0;
    priority_queue<node> que;
    que.push((node){1, origin});
    
    while(!que.empty()){
        node t = que.top();
        que.pop();
        if (vis[t.position]) continue;
        vis[t.position] = 1;

        int index = vertex[t.position];
        while(index != -1){
            int u = edge[index].to;
            double w = edge[index].weight;

            if (t.distance * w > dis[u]){
                dis[u] = t.distance * w;
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
        add(v2, v1, w);
    }
    scanf("%d %d", &s, &e);
    dijkstra(s);
    printf("%.8lf", 100.0/dis[e]);
    return 0;
}