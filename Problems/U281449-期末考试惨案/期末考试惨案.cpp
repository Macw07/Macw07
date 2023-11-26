#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#include <vector>
using namespace std;

int n, m, k, xi, yi, ti;
int sx, sy;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
char arr[1005][1005];
int bomb[1005][1005];
bool vis[1005][1005];

struct dimension{
    int x;
    int y;
};

struct node{
    int x;
    int y;
    int steps;
    vector<dimension> path; 
};

queue<node> que;

void bfs(){
    vis[sx][sy] = 1;
    que.push((node){sx, sy, 0});
    que.back().path.push_back((dimension){sx, sy});
    while(!que.empty()){
        node t = que.front();
        if (arr[t.x][t.y] == '@'){
            printf("%d\n", t.steps);
            for (int i=0; i<t.path.size()-1; i++){
                printf("(%d,%d)->", t.path[i].x, t.path[i].y);
            }
            printf("(%d,%d)\n", t.x, t.y);
            return;
        }
        for (int i=0; i<4; i++){
            int cx = t.x + dx[i];
            int cy = t.y + dy[i];
            if (cx < 1 || cy < 1 || cx > n || cy > m || vis[cx][cy] || arr[cx][cy] == '#') continue;
            if (t.steps+1 >= bomb[cx][cy]) continue;
            vis[cx][cy] = 1;
            que.push((node){cx, cy, t.steps+1, t.path});
            que.back().path.push_back((dimension){cx, cy});
        }
        que.pop();
    }
    printf("Impossible\n");
    return;
}

int main(){
    scanf("%d %d", &n, &m);
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            cin >> arr[i][j];
            if (arr[i][j] == '&') sx = i, sy = j;
        }
    }
    scanf("%d", &k);
    memset(bomb, 0x7f, sizeof bomb);
    for (int i=1; i<=k; i++){
        scanf("%d %d %d", &xi, &yi, &ti);
        bomb[xi][yi] = ti;
    }
    bfs();
    return 0;
}