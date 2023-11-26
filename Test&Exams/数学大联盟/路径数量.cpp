#include <iostream>
#include <algorithm>
#include <list>
#include <cstring>
using namespace std;

int ans = 0;
int map[105][105];
int vis[105][105];
int n;  // 表示有n个节点
int start, endd;

void dfs(int current, int steps){
    if (current == endd){
        ans++;
    }
    for (int i=1; i<=n; i++){
        if (vis[i][current] == 0 && vis[current][i] == 0 && map[current][i] == 1 && current != i){
            vis[current][i] = 1;
            vis[i][current] = 1;
            dfs(i, steps+1);
            vis[current][i] = 0;
            vis[i][current] = 0;
        }
    }
    return;
}

int main(){
    cin >> n;
    for (int i=0; i<n; i++){
        int k, m;
        cin >> k;
        while(cin >> m){
            if (m == 0) break;
            map[k][m] = map[m][k] = 1;
        }
    }
    cin >> start >> endd;
    dfs(start, 0);
    cout << ans << endl;
    return 0;
}