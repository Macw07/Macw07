#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

int n, m, k;
int arr[105][105];
int vis[105][105];
// 四个方向：上、右、下、左
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

struct node{
    int x;
    int y;
    int steps;
};

struct dimension{
    int x;
    int y;
};

dimension memo[105][105][105];
queue<node> que;

// 如果有一堆的Cindy碰撞
dimension dfs(int x, int y, int steps){
    // 记忆化搜索优化
    if (memo[x][y][steps].x) return memo[x][y][steps];

    bool flag = true;
    int ax = x, ay = y;
    for (int i=0; i<4; i++){
        int cx = x + dx[i];
        int cy = y + dy[i];
        if (cx < 1 || cy < 1 || cx > n || cy > m) continue;
        if (arr[cx][cy] != -1 && (arr[cx][cy] + steps)%4 == 4-i) {
            int t1 = -dx[i];
            int t2 = -dy[i];
            if (ax + t1 < 1 || ay + t2 < 1 || ax + t1 > n || ay + t2 > m) continue;
            ax += t1, ay += t2;
            flag = false;
        }
    }

    if (flag) return memo[x][y][steps] = (dimension){x, y};
    return memo[x][y][steps] = dfs(ax, ay, steps);
}

void bfs(){
    while(que.size()){
        node top = que.front();
        if (top.x == n && top.y == m){
            cout << top.steps << endl;
            exit(0);
            return ;
        }
        for (int i=0; i<5; i++){
            int cx = top.x + dx[i];
            int cy = top.y + dy[i];
            if (cx < 1 || cy < 1 || cx > n || cy > m || arr[cx][cy] != -1 || vis[cx][cy]) continue;
            // 超级大模拟 - 模拟被Cindy弹飞
            dimension new_position = dfs(cx, cy, top.steps+1);
            // 调试 {
            // if (new_position.x != cx || new_position.y != cy){
            //     cout << cx << " " << cy << " " << top.steps+1 << endl;
            // }
            // if (cx == 5 && cy == 2 && top.steps+1 == 5){
            //     cout << new_position.x << " " << new_position.y << endl;
            // }
            // }
            vis[cx][cy] += 1;
            que.push((node){new_position.x, new_position.y, top.steps+1});
        }
        que.push((node){top.x, top.y, top.steps+1});
        que.pop();
    }
    return ;
}

int main(){
    scanf("%d %d %d", &n, &m, &k);
    memset(arr, -1, sizeof arr);
    for (int i=1; i<=k; i++){
        int x, y, d;
        scanf("%d %d %d", &x, &y, &d);
        arr[x][y] = d;
    }
    que.push((node){1, 1, 0});
    bfs();
    cout << "Impossible" << endl;
    return 0;
}