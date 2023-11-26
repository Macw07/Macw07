#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int n, m, ans = 0;
char arr[505][505];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
struct node{int x, y;};
queue<node> que;

void bfs(){
    que.push((node){0, 0});
    arr[0][0] = 'X';
    while(!que.empty()){
        node front = que.front();
        for (int i=0; i<4; i++){
            int cx = front.x + dx[i];
            int cy = front.y + dy[i];
            if (cx < 0 || cy < 0 || cx > n+1 || cy > m+1) continue;
            if (arr[cx][cy] != '*' && arr[cx][cy] != 'X'){
                arr[cx][cy] = 'X';
                que.push((node){cx, cy});
            }
        }
        que.pop();
    }
    return;
}

int main(){
    cin >> n >> m;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            cin >> arr[i][j];
        }
    }
    bfs();
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            if (arr[i][j] == '0') ans++;
            // cout << arr[i][j];
        }
        // cout << endl;
    }
    cout << ans << endl;
    return 0;
}