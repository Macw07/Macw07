#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 1e5+5;
struct node{
    int v1, v2;
    int weight;
} edge[N];
int t, n, m, ei;
int dis[N];

bool bellman_ford(int s){
    // memset(dis, 0x7f, n+5);
    for (int i=1; i<=n; i++) dis[i] = 0x7f7f7f7f;
    dis[s] = 0;
    // bf算法：要经过v-1轮松弛，每轮松弛要遍历所有边，时间复杂度O(ve)。
    for (int i=1; i<n; i++){
        bool flag = 1;  // 优化
        for (int j=1; j<ei; j++){  // 遍历每一条边
            int u = edge[j].v1;
            int v = edge[j].v2;
            int w = edge[j].weight;
            if (dis[u] + w < dis[v] && dis[u] != 0x7f7f7f7f){
                dis[v] = dis[u] + w;
                flag = 0;
            }
        }
        if (flag) return false;
    }

    // 再走一轮，如果还可以被松弛，说明存在负环
    for (int j=1; j<ei; j++){  // 遍历每一条边
        int u = edge[j].v1;
        int v = edge[j].v2;
        int w = edge[j].weight;
        if (dis[u] + w < dis[v] && dis[u] != 0x7f7f7f7f){
            dis[v] = dis[u] + w;
            return true;
        }
    }

    return false;
}

int main(){
    scanf("%d", &t);
    while(t--){
        ei = 1;
        scanf("%d %d", &n, &m);
        for (int i=1; i<=m; i++){
            int v1, v2, w;
            scanf("%d %d %d", &v1, &v2, &w);
            if (w >= 0){  // 注意：非负！
                edge[ei++] = (node){v1, v2, w};
                edge[ei++] = (node){v2, v1, w};
            } else edge[ei++] = (node){v1, v2, w}; 
        }
        if (bellman_ford(1)) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}