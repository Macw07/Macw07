#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

const int MAX_ = 1e5+5;

/*
因此要求的就是1到v的最短奇数路径和最短偶数路径。
若v的阶段为偶数x，存在v的最短偶数路径y，满足x>=y，1即可为0。
若v的阶段为奇数x，存在v的最短奇数路径y，满足x>=y，1即可为0。
*/

int n, m, q, ei;
int vertex[MAX_];
struct perEdge{
    int to;
    int next;
} edge[2*MAX_];
int vis[MAX_];
int dis[MAX_][2];  // 0 表示偶数最短路，1表示基数最短路。

struct node{
    int distance;
    int position;
    bool friend operator < (node a, node b){
        return a.distance > b.distance;
    };
};

void dijkstra(int origin){
    memset(dis, 0x7f, sizeof dis);
    dis[origin][0] = 0;
    priority_queue<node> que;
    que.push((node){0, origin});
    while(!que.empty()){
        node t = que.top();
        que.pop();
        int index = vertex[t.position];
        while(index != 0){
            int u = edge[index].to;
            int new_dis = t.distance + 1;
            if (new_dis % 2 == 1){
                if (new_dis < dis[u][1]){
                    dis[u][1] = new_dis;
                    que.push((node){new_dis, u});
                }
            } else {
                if (new_dis < dis[u][0]){
                    dis[u][0] = new_dis;
                    que.push((node){new_dis, u});
                }
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
    cin >> n >> m >> q;
    for (int i=1; i<=m; i++){
        int v1, v2;
        cin >> v1 >> v2;
        add(v1, v2), add(v2, v1);
    }
    dijkstra(1);
    while(q--){
        int a, l;
        cin >> a >> l;
        if (l % 2 == 1){
            if (l >= dis[a][1]){
                cout << "Yes" << endl;
            } else cout << "No" << endl;
        } else{
            if (l >= dis[a][0]){
                cout << "Yes" << endl;
            } else cout << "No" << endl;
        }
    }
    return 0;
}