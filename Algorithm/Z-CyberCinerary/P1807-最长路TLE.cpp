#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m, ans;
int vis[1505];
bool flag = false;
struct node{
    int v;
    int w;
};

vector<node> G[1505];

void dfs(int index, int sum){
    if (index == n){
        flag = true;
        ans = max(ans, sum);
        return ;
    }
    int len = G[index].size();
    for (int i=0; i<len; i++){
        node next = G[index][i];
        if (vis[next.v]) continue;
        vis[next.v] = 1;
        dfs(next.v, sum + next.w);
        vis[next.v] = 0;
    }
    return ;
}

int main(){
    cin >> n >> m;
    for (int i=1; i<=m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        G[u].push_back((node){v, w});
    }
    dfs(1, 0);
    if (flag) cout << ans << endl;
    else cout << -1 << endl;
    return 0;
}