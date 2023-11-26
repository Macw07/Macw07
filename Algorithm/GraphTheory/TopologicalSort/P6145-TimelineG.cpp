#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;
const int MAXN = 1e5+5;

int n, m, c;
int inDegree[MAXN];
int ans[MAXN];

// 链式前向星
struct node{
    int to;
    int next;
    int weight;
} edge[MAXN];
int vertex[MAXN], ei;

void add(int v1, int v2, int w){
    edge[ei].to = v2;
    edge[ei].next = vertex[v1];
    edge[ei].weight = w;
    vertex[v1] = ei++;
    return ;
}

void topological_sort(){
    queue<int> que;
    for (int i=1; i<=n; i++){
        if (inDegree[i] == 0){
            que.push(i);
        }
    }
    while(!que.empty()){
        int t = que.front();
        que.pop();
        int index = vertex[t];
        while(index != -1){
            int u = edge[index].to;
            int w = edge[index].weight;
            ans[u] = max(ans[u], ans[t] + w);
            inDegree[u] -= 1;
            if (inDegree[u] == 0){
                que.push(u);
            }
            index = edge[index].next;
        }
    }
    return ;
}

int main(){
    cin >> n >> m >> c;
    memset(vertex, -1, sizeof vertex);
    for (int i=1; i<=n; i++) cin >> ans[i];
    for (int i=1; i<=c; i++){
        int u, v, w;
        cin >> u >> v >> w;
        add(u, v, w);
        inDegree[v] += 1;
    }
    topological_sort();
    for (int i=1; i<=n; i++) cout << ans[i] << endl;
    return 0;
}