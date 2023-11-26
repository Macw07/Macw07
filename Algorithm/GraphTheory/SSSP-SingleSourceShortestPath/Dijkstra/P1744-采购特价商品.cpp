#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cmath>
using namespace std;

int n, m, ei;
int vertex[105], vis[105];
int bs, es;
double ans[105];

struct coordinate{
    int x;
    int y;
} shops[105];

struct edges{
    int to;
    int next;
    double weight;
} edge[2005];

struct node{
    int weight;
    int position;
    bool friend operator < (node a, node b){
        return a.weight > b.weight;
    };
};

// 链式前向星
void add(int v1, int v2, double weight){
    ei += 1;
    edge[ei].to = v2;
    edge[ei].next = vertex[v1];
    edge[ei].weight = weight;
    vertex[v1] = ei;
    return ;
}

double distance(int point1, int point2){
    double res = 0;
    int x = pow(shops[point1].x - shops[point2].x, 2);
    int y = pow(shops[point1].y - shops[point2].y, 2);
    res = sqrt(x + y);
    return res;
}

void dijkstra(int origin){
    for (int i=1; i<=n; i++) ans[i] = 0x7f7f7f7f;
    ans[origin] = 0;
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
            double w = edge[index].weight;
            if (ans[t.position] + w < ans[u]){
                ans[u] = ans[t.position] + w;
                que.push((node){ans[u], u});
                // cout << ans[u] << endl;
            }
            index = edge[index].next;
        }
    }

    return ;
}

int main(){
    memset(vertex, -1, sizeof vertex);
    scanf("%d", &n);
    for (int i=1; i<=n; i++) scanf("%d %d", &shops[i].x, &shops[i].y);
    scanf("%d", &m);
    for (int j=1; j<=m; j++){
        int v1, v2;
        double weight;
        scanf("%d %d", &v1, &v2);
        weight = distance(v1, v2);
        add(v1, v2, weight), add(v2, v1, weight);
    }
    scanf("%d %d", &bs, &es);
    dijkstra(bs);
    printf("%.2lf", ans[es]);
    return 0;
}