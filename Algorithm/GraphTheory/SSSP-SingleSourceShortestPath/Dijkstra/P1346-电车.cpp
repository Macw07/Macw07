#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

const int MAXN = 1e5+5;

int n, a, b;
struct perEdge{
    int to;
    int next;
    int weight;
} edge[MAXN];
int vertex[105], ei;
int dis[105], vis[105];

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
    edge[ei].next = vertex[v1];
    edge[ei].weight = weight;
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
    scanf("%d %d %d", &n, &a, &b);
    for (int i=1; i<=n; i++){
        int k, v2;
        scanf("%d", &k);
        for (int j=1; j<=k; j++){
            scanf("%d", &v2);
            add(i, v2, j == 1 ? 0 : 1);
        }
    }
    dijkstra(a);
    if (dis[b] == 0x7f7f7f7f){
        printf("-1\n");
        return 0;
    }
    printf("%d\n", dis[b]);
    return 0;
}