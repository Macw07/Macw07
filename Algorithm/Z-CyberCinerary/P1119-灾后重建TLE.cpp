#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

int n, m, q;
int ti[205], ei;
int vertex[205];
struct perEdge{
    int to;
    int weight;
    int next;
} edge[100000];

int dis[205], vis[205];

struct node{
    int distance;
    int position;
    bool friend operator <  (node a, node b){
        return a.distance > b.distance;
    };
};

void dijkstra(int origin, int terminal, int times){
    memset(vis, 0, sizeof vis);
    memset(dis, 0x7f, sizeof dis);
    if (ti[origin] > times || ti[terminal] > times) return ;
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
            // 判断能否到达
            if (ti[u] > times){
                index = edge[index].next;
                continue;
            }
            if (dis[t.position] + w < dis[u]){
                dis[u] = dis[t.position] + w;
                que.push((node){dis[u], u});
            }
            index = edge[index].next;
        }
    }   
    return ;
}

void add(int v1, int v2, int w){
    ei += 1;
    edge[ei].to = v2;
    edge[ei].weight = w;
    edge[ei].next = vertex[v1];
    vertex[v1] = ei;
    return ;
}

int main(){
    cin >> n >> m;
    for (int i=1; i<=n; i++) cin >> ti[i];
    for (int i=1; i<=m; i++){
        int v1, v2, w;
        cin >> v1 >> v2 >> w;
        v1++, v2++;
        add(v1, v2, w);
        add(v2, v1, w);
    }
    cin >> q;
    for (int i=1; i<=q; i++){
        int v1, v2, t;
        cin >> v1 >> v2 >> t;
        v1++, v2++;
        dijkstra(v1, v2, t);
        if (dis[v2] == 0x7f7f7f7f) cout << -1 << endl;
        else cout << dis[v2] << endl;
    }
    return 0;
}