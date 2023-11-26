#include <iostream>
#include <queue>
using namespace std;

struct node{
    int x, y;
    int steps;
    bool friend operator < (node a, node b){
        return a.steps > b.steps;
    }
};

int n, m;
int sx, sy, ex, ey;
bool vis[105][105];
char map[105][105];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
priority_queue<node> que;

void bfs(){
    que.push((node){sx, sy});
    vis[sx][sy] = 1;
    while(!que.empty()){
        node t = que.top();
        if (t.x == ex && t.y == ey){
            printf("%d\n", t.steps);
            return;
        }
        for (int i=0; i<4; i++){
            int cx = t.x + dx[i];
            int cy = t.y + dy[i];
            if (cx < 1 || cy < 1 || cx > n || cy > m || vis[cx][cy] || map[cx][cy] == '#') continue;
            vis[cx][cy] = 1;
            if (map[cx][cy] == '-' || map[cx][cy] == 'O'){
                que.push((node){cx, cy, t.steps+1});
            } else if (map[cx][cy] == 'D'){
                que.push((node){cx, cy, t.steps+2});
            }
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
            cin >> map[i][j];
            if (map[i][j] == 'S'){
                sx = i, sy = j;
            }
            else if (map[i][j] == 'O'){
                ex = i, ey = j;
            }
            else if (map[i][j] == 'T'){
                for (int k=0; k<4; k++){
                    int cx = i + dx[k];
                    int cy = j + dy[k];
                    if (cx < 1 || cy < 1 || cx > n || cy > m) continue;
                    map[cx][cy] = '#';
                }
            }
        }
    }
    bfs();
    return 0;
}