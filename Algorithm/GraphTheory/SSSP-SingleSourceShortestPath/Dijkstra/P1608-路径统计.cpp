#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

int n, m, ei;
int arr[2005][2005];
int dis[2005], vis[2005];
int vertex[2005];
int total_path[2005];

struct perEdge{
    int to;
    int next;
    int weight;
} edge[4000005];

struct node{
    int dis;
    int position;
    bool friend operator < (node a, node b){
        return a.dis > b.dis;
    }
};

void add(int v1, int v2, int w){
    ei += 1;
    edge[ei].to = v2;
    edge[ei].weight = w;
    edge[ei].next = vertex[v1];
    vertex[v1] = ei;
    return ;
}

void dijkstra(int origin){
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
        int index = vertex[t.position];
        while(index != 0){
            int u = edge[index].to;
            int w = edge[index].weight;
            if (dis[t.position] + w < dis[u]){
                dis[u] = dis[t.position] + w;
                que.push((node){dis[u], u});
            }
            index = edge[index].next;
        }
    }
    return ;
}

int dfs(int node, int weight){
    if (total_path[node]){
        return total_path[node];
    }
    if (node == n){
        return 1;
    }
    int index = vertex[node];
    while(index != 0){
        int u = edge[index].to;
        if (!vis[u]){
            int w = edge[index].weight;
            vis[u] = 1;
            if(weight + w <= dis[u]){
                total_path[node] += dfs(u, weight + w);
            }
            vis[u] = 0;
        }
        index = edge[index].next;
    }
    return total_path[node];
}

int main(){
    freopen("P1608_9.in", "r", stdin);
    scanf("%d %d", &n, &m);
    int v1, v2, w;
    for (int i=1; i<=m; i++){
        scanf("%d %d %d", &v1, &v2, &w);
        if (arr[v1][v2] == w) continue;
        arr[v1][v2] = w;
        add(v1, v2, w);
    }
    dijkstra(1);
    if (dis[n] == 0x7f7f7f7f){
        cout << "No answer" << endl;
        return 0;
    }
    for (int i=1; i<=n; i++) {
        vis[i] = 0;
    }
    cout << dis[n] << " " << dfs(1, 0) << endl;
    return 0;
}