#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

const int MAXN = 100010;
int n, m, ans;
int vis[MAXN];
vector<int> G[MAXN];

void dfs(int node, int d){
    if (vis[node]) return ;
    vis[node] = d;
    ans = max(node, ans);
    for (int i=0; i<G[node].size(); i++) dfs(G[node][i], d);
    return ;
}

int main(){
    scanf("%d %d", &n, &m);
    for (int i=0; i<m; i++){
        int u, v;
        scanf("%d %d", &u, &v);
        G[v].push_back(u);  // 反向建边
    }
    for (int i=n; i>=1; i--) dfs(i, i);
    for (int i=1; i<=n; i++) cout << vis[i] << ' ';
    return 0;
}