#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

/*
这道题的核心部分在于，我们该如何找到一条路线，让从1到s1, s2的路线尽量的重合，并且满足时间分别小于t1, t2。
思路：找到一个中转节点k表示从1节点到k节点是去往s1, s2的重复路径。遍历每一个节点找到节点k即可。
*/

int n, m, ei;
int s1, t1, s2, t2;
int vertex[3005];
struct perEdge{
    int to;
    int next;
} edge[10005];
int dis[3005][3], vis[3005];

struct node{
    int distance;
    int position;
    bool friend operator < (node a, node b){
        return a.distance > b.distance;
    };
};

void dijkstra(int origin, int round){
    for (int i=1; i<=n; i++){
        dis[i][round] = 0x7f7f7f7f;
        vis[i] = 0;
    }
    dis[origin][round] = 0;
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
            if (dis[t.position][round] + 1 < dis[u][round]){
                dis[u][round] = dis[t.position][round] + 1;
                que.push((node){dis[u][round], u});
            }
            index = edge[index].next;
        }
    }
    return ;
}

void add(int v1, int v2){
    ei += 1;
    edge[ei].to = v2;
    edge[ei].next = vertex[v1];
    vertex[v1] = ei;
    return ;
}

int main(){
    cin >> n >> m;
    for (int i=1; i<=m; i++){
        int v1, v2;
        cin >> v1 >> v2;
        add(v1, v2);
        add(v2, v1);
    }
    cin >> s1 >> t1 >> s2 >> t2;
    dijkstra(1, 0);
    dijkstra(s1, 1);
    dijkstra(s2, 2);
    int ans = -1;
    for (int i=1; i<=n; i++){
        int dis1 = dis[i][0] + dis[i][1];
        int dis2 = dis[i][0] + dis[i][2];
        int tr = dis[i][0] + dis[i][1] + dis[i][2];
        if (dis1 <= t1 && dis2 <= t2){
            ans = max(ans, m - tr);
        }

    }
    cout << ans << endl;
    return 0;
}