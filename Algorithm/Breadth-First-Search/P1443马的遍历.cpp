#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

int dx[8]={-1,-2,-2,-1,1,2,2,1};
int dy[8]={2,1,-1,-2,2,1,-1,-2};
int n, m, sx, sy;

struct node{
    int x;
    int y;
    int steps;
};

queue<node> q;
int vis[405][405] = {};
int ans[405][405] = {};

void bfs(){
    while(!q.empty()){
        node c = q.front();
        ans[c.x][c.y] = min(ans[c.x][c.y], c.steps);
        for (int i=0; i<8; i++){
            int cx = c.x + dx[i];
            int cy = c.y + dy[i];
            if (cx > n || cy > m || cx < 1 || cy < 1 || vis[cx][cy] == 1) continue;
            vis[cx][cy] = 1;
            q.push((node){cx, cy, c.steps+1});
            
        }
        q.pop();
    }
}

int main(){
    cin >> n >> m >> sx >> sy;
    memset(ans, 0x7f, sizeof(ans));
    q.push((node){sx, sy, 0});
    vis[sx][sy] = 1;

    bfs();

    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            if (ans[i][j] != 0x7f7f7f7f){
                printf("%-5d", ans[i][j]);
            } else{
                printf("%-5d", -1);
            }
        }
        cout << endl;
    }

    return 0;
}