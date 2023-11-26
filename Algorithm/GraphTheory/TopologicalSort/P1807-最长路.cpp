#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

int n, m, ei;
int dp[1505];
int inDegree[1505];
int vertex[1505];
struct perEdge{
    int to;
    int weight;
    int next;
} edge[100005];
queue<int> que;
queue<int> ans_n;

void topological_sort(){
    for (int i=1; i<=n; i++){
        if (inDegree[i] == 0){
            que.push(i);
        }
        dp[i] = -0x7f7f7f7f;
    }
    dp[1] = 0;
    while(!que.empty()){
        int t = que.front();
        que.pop();
        ans_n.push(t);
        int index = vertex[t];
        while(index != 0){
            int u = edge[index].to;
            int w = edge[index].weight;
            inDegree[u] -= 1;
            if (inDegree[u] == 0){
                que.push(u);
            }
            dp[u] = max(dp[u], dp[t] + w);
            index = edge[index].next;
        }
    }
    return ;
}

void add(int v1, int v2, int weight){
    ei += 1;
    edge[ei].to = v2;
    edge[ei].weight = weight;
    edge[ei].next = vertex[v1];
    vertex[v1] = ei;
    inDegree[v2] += 1;
    return ;
}

int main(){
    scanf("%d %d", &n, &m);
    for (int i=1; i<=m; i++){
        int v1, v2, w;
        scanf("%d %d %d", &v1, &v2, &w);
        add(v1, v2, w);
    }
    topological_sort();
    if (dp[n] == -0x7f7f7f7f) printf("-1\n");
    else printf("%d\n", dp[n]);
    return 0;
}