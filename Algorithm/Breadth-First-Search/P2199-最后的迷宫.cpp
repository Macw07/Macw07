#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN = 2e6 + 5;
int n, m;
int dx[] = {0, 1, -1, 0, 1, 1, -1, -1};
int dy[] = {1, 0, 0, -1, 1, -1, 1, -1};
char map[MAXN];
bool vis[MAXN];
int ax, ay, hx, hy, flag;

struct node{
    int x;
    int y;
    int steps;
};

inline bool check2(int cx, int cy){
    return !(cx < 1 || cy < 1 || cx > n || cy > m || map[(cx-1)*m+cy] == 'X');
}

// 往八个方向拓展。
bool check(int x, int y){
    for (int i=0; i<8; i++){
        int cx = x + dx[i];
        int cy = y + dy[i];
        while(check2(cx, cy)){
            if (cx == ax && cy == ay) return 1;
            cx += dx[i];
            cy += dy[i];
        }
    }
    return 0;
}

void bfs(int ax, int ay, int hx, int hy){
    queue<node> que;
    memset(vis, 0, sizeof vis);
    vis[(hx-1)*m+hy] = 1;
    que.push((node){hx, hy, 0});

    while(!que.empty()){
        node t = que.front();
        que.pop();

        if (check(t.x, t.y)){
            cout << t.steps << endl;
            return ;
        }

        for (int i=0; i<4; i++){
            int cx = t.x + dx[i];
            int cy = t.y + dy[i];
            if (cx < 1 || cy < 1 || cx > n || cy > m) continue;
            if (vis[(cx-1)*m+cy] || map[(cx-1)*m+cy] == 'X') continue;
            vis[(cx-1)*m+cy] = 1;
            que.push((node){cx, cy, t.steps + 1});
        }
    }
    cout << "Poor Harry" << endl;
    return ;
}

int main(){
    scanf("%d %d", &n, &m);
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            cin >> map[(i-1)*m + j];
        }
    }
    while(true){
        scanf("%d %d %d %d", &ax, &ay, &hx, &hy);
        if (ax == 0 && ax == ay && ay == hx && hx == hy) break;
        bfs(ax, ay, hx, hy);
    }
    return 0;
}