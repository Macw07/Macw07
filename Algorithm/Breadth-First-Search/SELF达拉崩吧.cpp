#include <iostream>
#include <algorithm>
#include <queue>   // BFS需要用到队列以及优先队列
using namespace std;

long long h, n, m;  // 高、长、宽
char map[150][1105][1105];  // 创建一个三维地图，高、长、宽

struct location{
    long long h, x, y;
};

location start;
location portal[35][10000];
long long portal_times[35];

struct node{
    long long h, x, y;
    long long steps;
    bool friend operator < (node a,node b){
		return a.steps>b.steps;  //>表示step从小到排 
	};
};

priority_queue<node> q;
bool vis[150][1105][1105];  // 定义变量存储是否经过

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

bool flag = 0;
bool knight = 0;
bool princess = 0;

void bfs(){
    q.push((node){start.h, start.x, start.y, 0});
    vis[start.h][start.x][start.y] = 1;

    // 获取队首元素并弹出
    while(!q.empty()){
        node t = q.top();
        // 判断是否拯救到了公主                         
        if (map[t.h][t.x][t.y] == 'E'){
            cout << t.steps << endl;
            flag = 1;
            return;
        }
        // 不断向四个方向遍历
        for (int i=0; i<4; i++){
            long long sx = t.x + dx[i];
            long long sy = t.y + dy[i];
            // 过滤掉元素
            if (sx < 1 || sx > n || sy < 1 || sy > m || vis[t.h][sx][sy]==1 || map[t.h][sx][sy] == '#') continue;
            vis[t.h][sx][sy] = 1;
            // 开始拓展
            // 正常移动
            q.push((node){t.h, sx, sy, t.steps+1});
            // 如果遇到楼层传输器: 新增上去一层以及下去一层
            if (map[t.h][sx][sy] == '@'){
                if (t.h <= h-1 && !vis[t.h+1][sx][sy] && map[t.h+1][sx][sy]!='#'){
                    q.push((node){t.h+1, sx, sy, t.steps+3});
                    vis[t.h+1][sx][sy] = 1;
                }
                if (t.h >= 2 && !vis[t.h-1][sx][sy] && map[t.h-1][sx][sy]!='#'){
                    q.push((node){t.h-1, sx, sy, t.steps+3});
                    vis[t.h-1][sx][sy] = 1;
                }
            }
            // 如果遇到了传送门，就将所有的同类型传送门加入
            if (map[t.h][sx][sy] >= 'A' && map[t.h][sx][sy] <= 'Z' && map[t.h][sx][sy] != 'E' && map[t.h][sx][sy] != 'S'){
                int w = map[t.h][sx][sy]-'A';
                while(portal_times[w]){
                    location l = portal[w][portal_times[w]--];
                    if (vis[l.h][l.x][l.y]) continue;
                    vis[l.h][l.x][l.y] = 1;
                    q.push((node){l.h, l.x, l.y, t.steps+1});
                    // printf("%d %d %d\n", l.h, l.x, l.y);
                }
            }
        }
        q.pop();
    }
}

int main(){
    cin >> h >> n >> m;
    for (int i=1; i<=h; i++){
        for (int j=1; j<=n; j++){
            for (int k=1; k<=m; k++){
                cin >> map[i][j][k];
                // 不同位置的判断
                if (map[i][j][k] == 'S') {knight=1; start.h=i; start.x=j; start.y=k;}  // 入口判断
                // 剩下的几个传送门
                if (map[i][j][k] == 'E') {princess = 1;}
                else if (map[i][j][k] >= 'A' && map[i][j][k] <= 'Z' && map[i][j][k] != 'E'){
                    int t = map[i][j][k]-'A';
                    portal[t][portal_times[t]++] = (location){i, j, k};
                }
            }
        }
    }
    if (knight == 0 || princess == 0){
        cout << -1 << endl;
        return 0;
    }
    bfs();
    if (flag == 0) cout << -1 << endl;
    return 0;
}