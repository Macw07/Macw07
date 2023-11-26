#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

int n;
int arr[505][505];
int vis[505][505];
int dx[] = {0, 1, -1, 0, 0};
int dy[] = {1, 0, 0, -1, 0};
struct node{int x, y, t;};
queue<node> que;

void bfs(){
    que.push((node){0, 0, 0});
    while(!que.empty()){
        node t = que.front();
        if (arr[t.x][t.y] == -1){
            cout << t.t << endl;
            return;
        }
        for (int i=0; i<4; i++){
            int cx = t.x + dx[i];
            int cy = t.y + dy[i];
            if (cx < 0 || cy < 0 || cx > 302 || cy > 302 || vis[cx][cy] || arr[cx][cy] >= 0 && arr[cx][cy] <= t.t+1) continue;
            que.push((node){cx, cy, t.t+1});
            vis[cx][cy] = 1;
            // printf(":: %d %d %d\n", cx, cy, t.t+1);
        }
        que.pop();
    }
    cout << -1 << endl;
    return;
}

int main(){
    cin >> n;
    memset(arr, -1, sizeof arr);
    for (int i=0; i<n; i++){
        int x, y, t;
        cin >> x >> y >> t;
        for (int j=0; j<=4; j++){
            int cx = x + dx[j];
            int cy = y + dy[j];
            if (cx < 0 || cy < 0 || cx > 300 || cy > 300) continue;
            if (arr[cx][cy] != -1){
                arr[cx][cy] = min(arr[cx][cy], t);
            } else arr[cx][cy] = t;  // 所有为-1的格子是安全的格子
        }
    }
    bfs();
    // for (int i=0; i<10; i++){
    //     for (int j=0; j<10; j++){
    //         cout << arr[i][j] << "   ";
    //     }
    //     cout << endl;
    // }
    return 0;
}