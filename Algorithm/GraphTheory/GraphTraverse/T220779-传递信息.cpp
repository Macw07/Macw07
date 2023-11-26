#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, r, k;
int ans, flag;
vector<int> G[55];
int vis[55][55];

void dfs(int player, int rounds){
    if (rounds > k) return ;
    if (player == n-1 && rounds == k){
        flag = 1;
        ans += 1;
        return ;
    }
    for (int i=0; i<G[player].size(); i++){
        if (vis[player][G[player][i]]) continue;
        vis[player][G[player][i]] = 1;
        dfs(G[player][i], rounds+1);
    }
    return ;
}

int main(){
    cin >> n >> r >> k;
    for (int i=0; i<r; i++) {
        int v, t;
        cin >> v >> t;
        G[v].push_back(t);
    }
    dfs(0, 0);
    if (!flag) cout << 0 << endl;
    else cout << ans << endl;
    return 0;
}