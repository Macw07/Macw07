#include <iostream>
#include <queue>
using namespace std;

struct node{
    int x, y, steps;
    bool istp;
};

int n, m, cnt=0;
char arr[50][50];
int vis[50][50];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
node tp[50];
queue<node> q;

void bfs(){
    while(!q.empty()){
        node t = q.front();
        q.pop();
        if (t.x == n && t.y == m){
            cout << t.steps << endl;
            return;
        }
        // 如果走到传送门
        if (t.istp == 1){
            for (int i=0; i<cnt; i++){
                if (vis[tp[i].x][tp[i].y] == 0){
                    vis[tp[i].x][tp[i].y] = 1;
                    q.push((node){tp[i].x, tp[i].y, t.steps, 1});
                }
            }
        }
        for (int i=0; i<4; i++){
            int cx = t.x + dx[i];
            int cy = t.y + dy[i];
            if (cx > n || cy > m || cx < 1 || cy < 1 || vis[cx][cy] == 1 || arr[cx][cy] == '#') continue;
            vis[cx][cy] = 1;
            if (arr[cx][cy] == '$'){
                q.push((node){cx, cy, t.steps+1, 1});
            } else{
                q.push((node){cx, cy, t.steps+1, 0});
            } 
        }
    }
    cout << -1 << endl;
}

int main(){
    cin >> n >> m;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            cin >> arr[i][j];
            if (arr[i][j] == '$'){
                tp[cnt++] = (node){i, j, 0, 1};
            }
        }
    }
    vis[1][1] = 1;
    q.push((node){1, 1, 1, 0});
    bfs();
    return 0;
}