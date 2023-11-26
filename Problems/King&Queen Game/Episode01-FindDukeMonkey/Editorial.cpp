#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

int n, m, ans, total;
char map[30][30];
bool vis[30][30];
int dx[] = {0, 1, -1, 0};
int dy[] = {1, 0, 0, -1};

struct node{
    int x;
    int y;
    int steps;
};

void dfs(int x, int y, int steps){
    if (steps == ans && map[x][y] == '&'){
        total += 1;
        return ;
    }
    if (steps >= ans) return ;
    for (int i=0; i<4; i++){
        int cx = x + dx[i];
        int cy = y + dy[i];
        if (cx < 1 || cy < 1 || cx > n || cy > m || vis[cx][cy]) continue;
        if (map[cx][cy] == '#') continue;
        vis[cx][cy] = 1;
        dfs(cx, cy, steps+1);
        vis[cx][cy] = 0;
    }
    return ;
}

void bfs(int x, int y){
    queue<node> que;
    que.push((node){x, y, 0});
    vis[x][y] = 1;

    while(!que.empty()){
        node t = que.front();
        que.pop();
        if (map[t.x][t.y] == '&'){
            ans = t.steps;
            return ;
        }
        for (int i=0; i<4; i++){
            int cx = t.x + dx[i];
            int cy = t.y + dy[i];
            if (cx < 1 || cy < 1 || cx > n || cy > m || vis[cx][cy]) continue;
            if (map[cx][cy] == '#') continue;
            vis[cx][cy] = 1;
            que.push((node){cx, cy, t.steps + 1});
        }
    }
    return ;
}

int main(){
    // freopen("data/testcase020.in", "r", stdin);
    // freopen("data/testcase020.out", "w", stdout);
    cin >> n >> m;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            cin >> map[i][j];
        }
    }
    bfs(1, 1);
    memset(vis, 0, sizeof vis);
    dfs(1, 1, 0);
    if (total) cout << total << endl;
    else cout << -1 << endl;
    return 0;
}