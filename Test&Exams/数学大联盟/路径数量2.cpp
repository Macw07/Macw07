#include <iostream>
#include <algorithm>
#include <list>
#include <vector>
using namespace std;

int total;
int ans = 0;
int map[105][105];
int vis[105][105];
int pvis[100];
int n;  // 表示有n个节点
int start, endd;
vector<int> path;

void dfs(int current, int steps){
    if (steps > 2) return;
    if (current == endd && steps == 2){
        ans++;
        for (int i=0; i<path.size(); i++){
            cout << path[i] << "->";
            
        }
        cout << endl;
    }
    for (int i=1; i<=n; i++){
        if (vis[i][current] == 0 && vis[current][i] == 0 && map[current][i] == 1 && current != i){
            path.push_back(i);
            vis[current][i] = 1;
            vis[i][current] = 1;
            dfs(i, steps+1);
            vis[current][i] = 0;
            vis[i][current] = 0;
            path.pop_back();
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
    // cin >> start >> endd;
    for (int i=1; i<=n; i++){
        for (int j=i+1; j<=n; j++){
            path.clear();
            memset(vis, 0, sizeof vis);
            path.push_back(i);
            start = i;
            endd = j;
            dfs(start, 0);
        }
    }
    
    cout << ans << endl;
    return 0;
}