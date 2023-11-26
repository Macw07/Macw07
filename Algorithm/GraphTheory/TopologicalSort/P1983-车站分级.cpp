#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

/*
这道题的重点在于，如何找到班次和车站等级的关系，并适当建图。
在任意一段路程里，没有被停靠的站点的等级肯定是最低的，因此我们可以通过构造图来解决这个问题。
我们可以建一个边 edge(v1, v2)，表示车站v2的等级低于v1的等级。
最终就可以通过拓扑排序来解决问题（找拓扑排序中的最长路即可）。
*/

int n, m, ei, ans;
int vis[1005], arr[1005];
int G[1005][1005], top[1005];
int vertex[1005], inDegree[1005];
struct perEdge{
    int to;
    int next;
} edge[1000005];

void add(int v1, int v2){
    ei += 1;
    edge[ei].to = v2;
    edge[ei].next = vertex[v1];
    vertex[v1] = ei;
    return ;
}

void topological_sort(){
    queue<int> que;
    for (int i=1; i<=n; i++){
        if (inDegree[i] == 0){
            que.push(i);
            top[i] = 1;
        }
    }
    while(!que.empty()){
        int t = que.front();
        que.pop();
        int index = vertex[t];
        ans = max(ans, top[t]);
        while(index != 0){
            int u = edge[index].to;
            inDegree[u] -= 1;
            top[u] = max(top[u], top[t] + 1);
            if (inDegree[u] == 0) que.push(u);
            index = edge[index].next;
        }
    }
    return ;
}

int main(){
    cin >> n >> m;
    while(m--){
        int t, tmp;
        cin >> t;
        for (int i=1; i<=t; i++){
            cin >> arr[i];
            vis[arr[i]] += 1;
        }
        // 对于每一个没有被访问过的点建边
        for (int i=arr[1]; i<=arr[t]; i++){
            if (vis[i]) continue;
            for (int j=1; j<=t; j++){
                if (G[arr[j]][i]) continue;  // 如果之前有边了，就不管了
                G[arr[j]][i] = 1;
                inDegree[i] += 1;
                add(arr[j], i);
            }
        }
        memset(vis, 0, sizeof vis);
    }
    topological_sort();
    cout << ans << endl;
    return 0;
}