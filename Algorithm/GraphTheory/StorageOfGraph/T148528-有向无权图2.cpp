#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool flag = 0;
int n, m, a, b;
vector<int> G[200005];
int vis[2000005];

void dfs1(int node){
    if (node == b || flag){
        flag = 1;
        return ;
    }
    for (int i=0; i<G[node].size(); i++){
        int u = G[node][i];
        if (vis[u]) continue;
        vis[u] = 1;
        dfs1(u);
        vis[u] = 0;
    }
    return ;
}

void dfs2(int node){
    if (node == b || flag){
        flag = 1;
        return ;
    }
    for (int i=0; i<G[node].size(); i++){
        int u = G[node][i];
        if (u == -1) continue;
        G[node][i] = -1;
        dfs2(u);
    }
    return ;
}

int main(){
    cin >> n >> m >> a >> b;
    for (int i=1; i<=m; i++){
        int v1, v2;
        cin >> v1 >> v2;
        G[v1].push_back(v2);
    }
    dfs1(a);
    if (flag) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}