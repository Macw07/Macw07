#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

// 原来这道题只有两个传送门，我还以为有好多个呢。

int n, m;
char arr[310][310];
int vis[310][310];
int sx, sy;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

struct node{
    int x, y, times;
};

void find_another(int &x, int &y){
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            if (arr[i][j] == arr[x][y] && (x != i || y != j)){
                x = i, y = j;
                return ;
            }
        }
    }
    return ;
}

void bfs(){
    queue<node> que;
    vis[sx][sy] = 1;
    que.push((node){sx, sy, 0});
  
    while(que.size()){
        node t = que.front();
        if (arr[t.x][t.y] == '='){
            cout << t.times << endl;
            return ;
        }
        if (arr[t.x][t.y] >= 'A' && arr[t.x][t.y] <= 'Z') find_another(t.x, t.y);
        for (int i=0; i<4; i++){
            int cx = t.x + dx[i];
            int cy = t.y + dy[i];
            if (cx < 1 || cy < 1 || cx > n || cy > m || vis[cx][cy] || arr[cx][cy] == '#') continue;
            vis[cx][cy] = 1;
            que.push((node){cx, cy, t.times+1});
        }
        que.pop();
    }
    return ;
}

int main(){
    cin >> n >> m;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            cin >> arr[i][j];
            if (arr[i][j] == '@') sx = i, sy = j;
        }
    }
    bfs();
    return 0;
}