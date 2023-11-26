#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN = 1e4 + 5;
int n, m, ei, flag;
long long dis[MAXN];
struct perEdge{
    int v1;
    int v2;
    int weight;
} edge[MAXN];

void bellman_ford(int origin){
    memset(dis, 0x7f, sizeof dis);
    dis[origin] = 0;  // 切记，赋值为0！！！不是1。
    // 对所有的边，松弛 n-1次。
    for (int i=1; i<n; i++){
        for (int j=1; j<=ei; j++){
            int u = edge[j].v1;
            int v = edge[j].v2;
            int w = edge[j].weight;
            if (dis[u] + w < dis[v]){
                dis[v] = dis[u] + w;
            }
        }
    }
    flag = true;
    for (int j=1; j<ei; j++){
        int u = edge[j].v1;
        int v = edge[j].v2;
        int w = edge[j].weight;
        if (dis[u] + w < dis[v] && dis[u] != 0x7f7f7f7f){
            dis[v] = dis[u] + w;
            flag = false;
        }
    }
    if (!flag) {
        printf("Forever love");
        exit(0);
    }
    return ;
}

int main(){
    scanf("%d %d", &n, &m);
    for (int i=1; i<=m; i++){
        int v1, v2, w;
        scanf("%d %d %d", &v1, &v2, &w);
        edge[++ei] = (perEdge){v1, v2, -w};
    }

    // 可以是双向奔赴
    bellman_ford(1);
    int ans1 = dis[n];
    int tf1 = flag;

    bellman_ford(n);
    int ans2 = dis[1];
    int tf2 = flag;

    printf("%d", min(ans1, ans2));
    return 0;
}