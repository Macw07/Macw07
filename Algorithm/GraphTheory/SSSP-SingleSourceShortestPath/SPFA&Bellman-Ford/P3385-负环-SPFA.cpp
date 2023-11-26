#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

// 记得初始化！

int t, n, m, ei;
const int MN = 2e3 + 5;
const int MM = 6e3 + 5;

struct perEdge{
    int to;
    int next;
    int weight;
} edge[MM];
int vertex[MN], dis[MN], vis[MN], cnt[MN];

void add(int v1, int v2, int w){
    ei += 1;
    edge[ei].to = v2;
    edge[ei].weight = w;
    edge[ei].next = vertex[v1];
    vertex[v1] = ei;
    return ;
}

bool SPFA(int origin){
    memset(vis, 0, sizeof vis);
    memset(dis, 0x3f, sizeof dis);
    memset(cnt, 0, sizeof cnt);
    dis[origin] = 0;
    vis[origin] = 1;
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
                cnt[u] = cnt[t] + 1;

                if (cnt[u] >= n) return true;
                if (vis[u]) continue;
                
                que.push(u);
                vis[u] = 1;
                
            }
            index = edge[index].next;
        }
    }
    return false;
}

int main(){
    scanf("%d", &t);
    while(t--){
        ei = 0;
        for(int i=0;i<MM;i++) edge[i].next=0;
	    for(int i=0;i<MN;i++) vertex[i]=0;

        scanf("%d %d", &n, &m);
        int v1, v2, w;
        for (int i=1; i<=m; i++){
            scanf("%d %d %d", &v1, &v2, &w);
            add(v1, v2, w);
            if (w >= 0) add(v2, v1, w);
        }
        if (SPFA(1)) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}