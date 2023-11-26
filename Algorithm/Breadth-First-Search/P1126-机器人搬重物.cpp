#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

// Wrong #6: 不能提早判断，假如我要走两步，不能先判断vis数组，应该是到了这个点以后再判断
// Wrong #8: 因为整体网右边移动了，所以边界判断需要改成<=n&&<=m

int n, m;
int arr[55][55];
int vis[55][55][5];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int sx, sy, ex, ey;
char dir;

struct node{
    int x, y;
    int time, direction;
};

queue<node> que;

int convert(char s){
    if (s == 'N') return 0;
    else if (s == 'E') return 1;
    else if (s == 'S') return 2;
    else if (s == 'W') return 3;
    return -1;
}

void bfs(){
    que.push((node){sx, sy, 0, convert(dir)});
    vis[sx][sy][convert(dir)] = 1;
    while(que.size()){
        node t = que.front();
        if (t.x == ex && t.y == ey){
            cout << t.time << endl;
            exit(0);
        }
        for (int i=1; i<=3; i++){
            int cx = t.x + i*dx[t.direction];
            int cy = t.y + i*dy[t.direction];
            if (cx <= 0 || cy <= 0 || cx >= n || cy >= m || arr[cx][cy] || vis[cx][cy][t.direction] >= 2) break;  // 不能穿墙
            vis[cx][cy][t.direction] += 1;
            que.push((node){cx, cy, t.time+1, t.direction});
        }
        // 往左转和往右转
        int ld = (t.direction - 1 + 4) % 4;
        if (!vis[t.x][t.y][ld]) {
            vis[t.x][t.y][ld] += 1;
            que.push((node){t.x, t.y, t.time+1, ld});
        }
        int rd = (t.direction + 1) % 4;
        if (!vis[t.x][t.y][rd]) {
            vis[t.x][t.y][rd] += 1;
            que.push((node){t.x, t.y, t.time+1, rd});
        }
        que.pop();
    }
    return ;
}

int main(){
    scanf("%d %d", &n, &m);
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            int t;
            scanf("%d", &t);
            //如果当前格为障碍物，则它的四个顶点都不能走。
            if (t == 1) arr[i][j] = arr[i-1][j] = arr[i][j-1] = arr[i-1][j-1] = 1;
        }
    }
    scanf("%d %d %d %d %c", &sx, &sy, &ex, &ey, &dir);
    bfs();
    printf("-1\n");
    return 0;
}