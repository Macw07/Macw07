#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

int n, m, d, r;
char arr[1005][1005];
bool vis[1005][1005][3];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

struct node{
    int x, y, steps;
    bool magic;
};
queue<node> que;

void bfs(){
    que.push((node){1, 1, 0, 1});
    vis[1][1][1] = 1;
    int k = 5000;
    while(k && !que.empty()){
        node t = que.front();
        que.pop();
        if (t.x == n && t.y == m){
            cout << t.steps << endl;
            exit(0);
        }
        // cout << "1 " << t.x << ' ' << t.y << ' ' << t.magic << endl;
        for (int i=0; i<4; i++){
            int cx = t.x + dx[i];
            int cy = t.y + dy[i];
            if (cx < 1 || cy < 1 || cx > n || cy > m || arr[cx][cy] == '#' || vis[cx][cy][t.magic]) continue;
            vis[cx][cy][t.magic] = 1;
            // cout << cx << ' ' << cy << endl;
            que.push((node){cx, cy, t.steps + 1, t.magic});
        }
        if (t.magic == 1){
            int cx = t.x + d;
            int cy = t.y + r;
            if (cx < 1 || cy < 1 || cx > n || cy > m || arr[cx][cy] == '#' || vis[cx][cy][0]);
            else {
                // cout << cx << ' ' << cy << endl;
                vis[cx][cy][0] = 1;
                que.push((node){cx, cy, t.steps + 1, 0});
            }
        }
    }
    return ;
}; 

int main(){
    cin >> n >> m >> d >> r;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            cin >> arr[i][j];
        }
    }
    bfs();
    cout << -1 << endl;
    return 0;
}