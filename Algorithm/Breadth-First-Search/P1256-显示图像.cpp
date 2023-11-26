#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

int n, m;
char map[200][200];
int vis[200][200];
int ans[200][200];
int dx[] = {0, 1, -1, 0};
int dy[] = {1, 0, 0, -1};

struct node{
    int x, y;
    int steps;
};
queue<node> que;

void bfs(){
    while(que.size()){
        node t = que.front();
        for (int i=0; i<4; i++){
            int cx = dx[i] + t.x;
            int cy = dy[i] + t.y;
            if (cx < 1 || cy < 1 || cx > n || cy > m || vis[cx][cy] || map[cx][cy] == '1') continue;
            vis[cx][cy] = 1;
            ans[cx][cy] = t.steps + 1;
            que.push((node){cx, cy, t.steps+1});
        }
        que.pop();
    }
    return ;
}

int main(){
    cin >> n >> m;
    memset(ans, 0x7f, sizeof ans);
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            cin >> map[i][j];
        }
    }

    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            if (map[i][j] == '1') 
            que.push((node){i, j, 0});
            vis[i][j] = 0;
        }
    }

    bfs();

    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            if (map[i][j] == '1') cout << 0 << ' ';
            else cout << ans[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}