#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

/*
记录取模的横纵坐标x, y时，同时记录没有取模的坐标px, py
当第一次走这个迷宫的时候，x, y和px, py肯定是分别相等的
所以只要走到的一个点的x, y与px, py不相同，那这个点一定是被走了第二遍。
*/

int n, m, flag;
int dx[] = {0, 1, -1, 0};
int dy[] = {1, 0, 0, -1};
char arr[1600][1600];
int vis[1600][1600][3];

// struct node{
//     int x;
//     int y;
//     int round;
//     bool friend operator < (node a, node b){
//         return a.round > b.round;
//     }
// };

// bool bfs(int sx, int sy){
//     vis[1][sx][sy] = 1;
//     priority_queue<node> que;
//     que.push((node){sx, sy, 1});
    
//     while(!que.empty()){
//         node t = que.top();
//         que.pop();
//         if (t.round == 2 && vis[1][t.x][t.y]){
//             // cout << t.x << " " << t.y << endl;
//             return true;
//         }
//         vis[t.round][t.x][t.y] = 1;
//         for (int i=0; i<4; i++){
//             int cx = t.x + dx[i];
//             int cy = t.y + dy[i];
//             if (cx < 0 || cy < 0 || cx >= n || cy >= m){
//                 // 边缘条件处理一下
//                 cx = (cx + n) % n;
//                 cy = (cy + m) % m;
//                 // 注意：这里要特判不能走回去
//                 if (arr[cx][cy] == '#' || vis[t.round][cx][cy] || vis[1][cx][cy]) continue;
//                 vis[2][cx][cy] = 1;
//                 cout << cx << " " << cy << endl;
//                 que.push((node){cx, cy, 2});
//             } else{
//                 if (arr[cx][cy] == '#' || vis[t.round][cx][cy]) continue;
//                 vis[1][cx][cy] = 1;
//                 que.push((node){cx, cy, 1});
//             }
//         }
//     }
//     return false;
// }

void dfs(int x, int y, int px, int py){
    // cout << x << " " << y << endl;
    if (flag) return;
    // 如果已经走到了访问过的地方，直接返回结果即可
    // 0 表示是否走过，1 表示走过的x坐标，2 表示走过的y坐标。
    if (vis[x][y][0] == 1 && (vis[x][y][1] != px || vis[x][y][2] != py)){
        // cout << x << ' ' << y << endl;
        flag = 1;
        return ;
    }
    vis[x][y][0] = 1, vis[x][y][1] = px, vis[x][y][2] = py;
    for (int i=0; i<4; i++){
        int cx = (n + x + dx[i]) % n;
        int cy = (m + y + dy[i]) % m;
        int ox = dx[i] + px, oy = dy[i] + py;
        if (arr[cx][cy] == '#') continue;
        if (!vis[cx][cy][0] || vis[cx][cy][1] != ox || vis[cx][cy][2] != oy){
            dfs(cx, cy, ox, oy);
        }
    }
    return ;
}

int main(){
    while(cin >> n >> m){
        int sx, sy; flag = 0;
        memset(arr, 0, sizeof arr);
        memset(vis, 0, sizeof vis);
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++){
                cin >> arr[i][j];
                if (arr[i][j] == 'S'){
                    sx = i, sy = j;
                }
            }
        }
        dfs(sx, sy, sx, sy);
        if (flag) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}