#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

struct node{
    int to;
    int next;
} edge[10005];
int k, n, m, ei, cnt;
int ans[1005], vis[1005];
int cows[1005], vertex[1005];

void add(int v1, int v2){
    ei = ei + 1;
    edge[ei].to = v2;
    edge[ei].next = vertex[v1];
    vertex[v1] = ei;
    return ;
}

void dfs(int node){
    ans[node] += 1;
    int index = vertex[node];
    while(index){
        int t = edge[index].to;
        if (vis[t]) {
            index = edge[index].next;
            continue;
        }
        vis[t] = 1;
        dfs(t);
        index = edge[index].next;
    }
    return ;
}

int main(){
    scanf("%d %d %d", &k, &n, &m);
    for (int i=1; i<=k; i++) cin >> cows[i];
    for (int i=1; i<=m; i++){
        int v1, v2;
        scanf("%d %d", &v1, &v2);
        add(v1, v2);
    }
    for (int i=1; i<=k; i++){
        vis[cows[i]] = 1;
        dfs(cows[i]);
        memset(vis, 0, sizeof vis);
    }
    for (int i=1; i<=n; i++){
        if (ans[i] == k){
            cnt += 1;
        }
    }
    cout << cnt << endl;
    return 0;
}