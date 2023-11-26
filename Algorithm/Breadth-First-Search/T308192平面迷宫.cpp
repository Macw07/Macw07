#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int n, m;
char arr[1005][1005];
bool vis[1005][1005];
int dx[] = {1, 0, 0, -1};
int dy[] = {0, -1, 1, 0};
char direction[] = {'D', 'L', 'R', 'U'};

struct node{
    int x;
    int y;
    int steps;
    string path;
};

queue<node> que;

void bfs(){
    que.push((node){1, 1, 0, ""});
    vis[1][1] = 1;
    while(!que.empty()){
        node now = que.front();
        // 判断有没有到终点
        if (now.x == n && now.y == m){
            cout << now.steps << endl;
            cout << now.path << endl;
            return;
        }

        // 向四个方向拓展
        for (int i=0; i<4; i++){
            int cx = now.x + dx[i];
            int cy = now.y + dy[i];
            // 判断这个方向是否可行
            if (cx < 1 || cy < 1 || cx > n || cy > m || vis[cx][cy] || arr[cx][cy] == '1') continue;
            vis[cx][cy] = 1;
            que.push((node){cx, cy, now.steps+1, now.path+direction[i]});
        }
        que.pop();
    }
}

int main(){
    cin >> n >> m;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            cin >> arr[i][j];
        }
    }
    bfs();
    return 0;
}