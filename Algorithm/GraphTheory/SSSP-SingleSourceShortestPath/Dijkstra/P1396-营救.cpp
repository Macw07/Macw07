#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

int n, m, s, t;
int ei, max_;
int dis[10005];
int vis[10005];
int vertex[10005];
struct perEdge{
    int to;
    int next;
    int weight;
} edge[40005];

struct node{
    int distance;
    int position;
    bool friend operator < (node a, node b){
        return a.distance > b.distance;
    };
};

void add(int v1, int v2, int w){
    ei += 1;
    edge[ei].to = v2;
    edge[ei].weight = w;
    edge[ei].next = vertex[v1];
    vertex[v1] = ei;
    return ;
}

bool check(int mid){
    memset(dis, 0x7f, sizeof dis);
    memset(vis, 0, sizeof vis);
    dis[s] = 0;
    queue<node> que;
    que.push((node){0, s});
    while(!que.empty()){
        node t = que.front();
        que.pop();
        if (vis[t.position]) continue;
        vis[t.position] = 1;
        int index = vertex[t.position];
        while(index != 0){
            int u = edge[index].to;
            int w = edge[index].weight;
            if (w > mid) {
                index = edge[index].next;
                continue;
            }
            if (dis[t.position] + w < dis[u]){
                dis[u] = dis[t.position] + w;
                que.push((node){dis[u], u});
                // cout << u << " " << dis[u] << endl;
            }
            index = edge[index].next;
        }
    }
    return dis[t] != 0x7f7f7f7f;

}

int main(){
    cin >> n >> m >> s >> t;
    for (int i=1; i<=m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        add(u, v, w);
        add(v, u, w);
        max_ = max(max_, w);
    }
    int l = 0, r = max_, ans;
    while(l <= r){
        int mid = (l+r) >> 1;
        if (check(mid)){
            r = mid - 1;
            ans = mid;
        } else l = mid + 1;
    }
    cout << ans << endl;
    return 0;
}