#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

const int MAXN = 1e4 + 5;
int n, m, ei, flag;
long long dis[MAXN];
int cnt[MAXN], vis[MAXN], vertex[MAXN];
struct perEdge{
    int to;
    int next;
    int weight;
} edge[MAXN];

void add(int v1, int v2, int w){
    ei += 1;
    edge[ei].to = v2;
    edge[ei].weight = w;
    edge[ei].next = vertex[v1];
    vertex[v1] = ei;
    return ;
}

bool bellman_ford(int origin){
    memset(dis, 0x7f, sizeof dis);
    dis[origin] = 0; 
    cnt[origin] = 1;
    queue<int> que;
    que.push(origin);
    
    while(!que.empty()){
        int t = que.front();
        que.pop();
        vis[t] = 0;
        int index = vertex[t];
        while(index){
            int u = edge[index].to;
            int w = edge[index].weight;
            if (dis[t] + w < dis[u]){
                dis[u] = dis[t] + w;
                if (!vis[u]){
                    vis[u] = 1;
                    que.push(u);
                    cnt[u] += 1;
                    if (cnt[u] >= n) return 1;
                }
            }
            index = edge[index].next;
        }
    }
    return 0;
}

int main(){
    scanf("%d %d", &n, &m);
    for (int i=1; i<=m; i++){
        int v1, v2, w;
        scanf("%d %d %d", &v1, &v2, &w);
        add(v1, v2, -w);
    }

    // 可以是双向奔赴
    int f1 = bellman_ford(1);
    int ans1 = dis[n];

    int f2 = bellman_ford(n);
    int ans2 = dis[1];

    if (f1 || f2) printf("Forever love");
    else printf("%d", min(ans1, ans2));
    return 0;
}