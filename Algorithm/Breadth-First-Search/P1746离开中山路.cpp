#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int n;
int vis[1005][1005];
char arr[1005][1005];
int x1, y1, x2, y2;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
struct node{
    int x, y;
    int steps;
};
queue<node> que;

void bfs(){
    // 将起点纳入队列，并标记
    que.push((node){x1, y1, 0});
    vis[x1][y1] = 1;
    while(!que.empty()){
        node front = que.front();
        if (front.x == x2 && front.y == y2){
            cout << front.steps << endl;
            exit(0);
        }
        for (int i=0; i<4; i++){
            int cx = front.x + dx[i];
            int cy = front.y + dy[i];
            if (cx < 1 || cy < 1 || cx > n || cy > n || vis[cx][cy] || arr[cx][cy] == '1') continue;
            que.push((node){cx, cy, front.steps+1});
            vis[cx][cy] = 1;
        }
        que.pop();
    }
    return;
}

int main(){
    cin >> n;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            cin >> arr[i][j];
        }
    }
    cin >> x1 >> y1 >> x2 >> y2;
    bfs();
    return 0;
}