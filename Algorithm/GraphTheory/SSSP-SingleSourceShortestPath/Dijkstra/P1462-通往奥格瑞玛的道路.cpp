#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

// 我是真的服了，为什么，这么粗心，初始化的时候初始化错了！！！！！

const int MAXN = 1e6;

int n, m, b;
int cities[MAXN], arr[MAXN];
int vertex[MAXN], ei, vis[MAXN];;
long long dis[MAXN];

struct perEdge{
    int to;
    int next;
    int weight;
} edge[MAXN];

void add(int v1, int v2, int weight){
    ei += 1;
    edge[ei].to = v2;
    edge[ei].weight = weight;
    edge[ei].next = vertex[v1];
    vertex[v1] = ei;
    return ;
}

struct node{
    int distance;
    int position;
    bool friend operator < (node a, node b){
        return a.distance > b.distance;
    };
};

void dijkstra(int origin, int limit){
    dis[origin] = 0;
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
            int w = edge[index].weight;
            
            if (dis[t.position] + w < dis[u] && cities[u] <= limit){
                dis[u] = dis[t.position] + w;
                que.push((node){dis[u], u});
            }

            index = edge[index].next;
        }
    }
    return ;
}

bool check(int mid){
    // 当金额上限为mid的时候，是否可以达到目的地
    if (mid < cities[1] || mid < cities[n]) return false;
    for (int i=1; i<=n; i++){
        vis[i] = 0;
        dis[i] = 2147483647;
    }
    dijkstra(1, mid);
    // cout << dis[n] << endl;
    if (dis[n] <= b) return true;
    return false;
}

void binary_search_for_result(){
    int lb = 1, rb = n, ans = arr[n];
    while (lb <= rb){
        int mid = (lb + rb) >> 1;
        if (check(arr[mid])){
            ans = arr[mid];
            rb  = mid - 1;
        } else lb = mid + 1;
    }
    printf("%d\n", ans);
    return ;
}

int main(){
    // freopen("12.in", "r", stdin);
    memset(vertex, -1, sizeof vertex);
    scanf("%d %d %d", &n, &m, &b);
    // cout << n << m << b << endl;
    for (int i=1; i<=n; i++) {
        scanf("%d", &cities[i]);
        arr[i] = cities[i];
    }
    sort(arr+1, arr+n+1);
    for (int i=1; i<=m; i++){
        int v1, v2, w;
        scanf("%d %d %d", &v1, &v2, &w);
        if (v1 == v2) continue;
        add(v1, v2, w);
        add(v2, v1, w);
    }
    if (!check(1e9)){
        printf("AFK\n");
        return 0;
    }
    binary_search_for_result();
    return 0;
}