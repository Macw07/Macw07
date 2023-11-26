#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

const int MAXM = 2e6 + 50;
const int MOD = 100003;

int v, e;
struct perEdge{
    int to;
    int next;
} edge[2*MAXM];
int vertex[MAXM], ei;
int dis[MAXM], ans[MAXM], vis[MAXM];

struct node{
    // distance 表示的是原点到position这个位置的距离。
    // position 就是顶点的编号，没有别的意思，单纯用来记录。
    int distance;
    int position;
    bool friend operator < (node a, node b){
        return a.distance > b.distance;
    };
};

void add(int v1, int v2){
    ei += 1;
    edge[ei].to = v2;
    edge[ei].next = vertex[v1];
    vertex[v1] = ei;
    return ;
}

void dijkstra(int origin){
    memset(dis, 0x7f, sizeof dis);
    dis[origin] = 0;  // 初始化原点
    ans[origin] = 1;  // 自己到自己的最短路径永远都是1
    priority_queue<node> que;
    que.push((node){0, 1});

    while(!que.empty()){
        node t = que.top();
        que.pop();
        if (vis[t.position]) continue;
        vis[t.position] = 1;
        // 事实证明，t.distance 和 dis[t.position]的值是一样的，可以混着用。 
        int index = vertex[t.position];
        while(index != -1){
            int u = edge[index].to;
            int w = 1;
            // 如果当前距离跟最短路的距离是一样的话，就让最短路的数量增加
            if (dis[t.position] + 1 == dis[u]){
                ans[u] = (ans[u] + ans[t.position]) % MOD;
            }
            // 如果上一步的距离加上这一步的距离小于原本的最短距离，更新答案
            if (dis[t.position] + 1 < dis[u]){
                dis[u] = dis[t.position] + 1;
                ans[u] = ans[t.position];
                que.push((node){dis[u], u});
            }
            index = edge[index].next;
        }
    }
    return ;
}

int main(){
    scanf("%d %d", &v, &e);
    memset(vertex, -1, sizeof vertex);
    for (int i=1; i<=e; i++){
        int v1, v2;
        scanf("%d %d", &v1, &v2);
        if (v1 == v2) continue;
        add(v1, v2);
        add(v2, v1);
    }
    dijkstra(1);
    for (int i=1; i<=v; i++) cout << ans[i] << endl;
    return 0;
}