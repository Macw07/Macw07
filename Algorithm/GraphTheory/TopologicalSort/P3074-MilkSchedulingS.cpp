#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

int n, m, ei, ans;
int dis[10005];
int ti[10005];
int vertex[10005];
int inDegree[10005];

struct perEdge{
    int to;
    int next;
}edge[500005];

void add(int v1, int v2){
    ei += 1;
    edge[ei].to = v2;
    edge[ei].next = vertex[v1];
    vertex[v1] = ei;
    return ;
}

void topological_sort(){
    queue<int> que;
    for (int i=1; i<=n;i++){
        if (inDegree[i] == 0){
            que.push(i);
            dis[i] = ti[i];
        }
    }
    while(!que.empty()){
        int t = que.front();
        // cout << t << " " << dis[t] << endl;
        que.pop();
        ans = max(ans, dis[t]);
        int index = vertex[t];
        while(index != 0){
            int u = edge[index].to;
            inDegree[u] -= 1;
            dis[u] = max(dis[u], dis[t] + ti[u]);
            if (inDegree[u] == 0){
                que.push(u);
            }
            index = edge[index].next;
        }
    }
    return ;
}

int main(){
    cin >> n >>m;
    for (int i=1; i<=n; i++){
        cin >> ti[i];
    }
    for (int i=1; i<=m; i++){
        int v1, v2;
        cin >> v1 >> v2;
        add(v1, v2);
        inDegree[v2] += 1;
    }
    topological_sort();
    cout << ans << endl;
    return 0;
}