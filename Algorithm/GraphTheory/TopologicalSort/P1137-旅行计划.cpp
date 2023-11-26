#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

int n, m, ei;
int dp[100005];
int inDegree[100005];
int vertex[100005];
struct perEdge{
    int to;
    int next;
} edge[200005];
queue<int> que;
queue<int> ans_n;

void topological_sort(){
    for (int i=1; i<=n; i++){
        if (inDegree[i] == 0){
            que.push(i);
            // dp[i] = 1;
        } 
        dp[i] = 1;
    }
    while(!que.empty()){
        int t = que.front();
        que.pop();
        ans_n.push(t);
        int index = vertex[t];
        while(index != 0){
            int u = edge[index].to;
            inDegree[u] -= 1;
            if (inDegree[u] == 0){
                que.push(u);
            }
            dp[u] = max(dp[u], dp[t] + 1);
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
    inDegree[v2] += 1;
    return ;
}

int main(){
    scanf("%d %d", &n, &m);
    for (int i=1; i<=m; i++){
        int v1, v2;
        scanf("%d %d", &v1, &v2);
        add(v1, v2);
    }
    topological_sort();
    for (int i=1; i<=n; i++) printf("%d\n", dp[i]);
    return 0;
}