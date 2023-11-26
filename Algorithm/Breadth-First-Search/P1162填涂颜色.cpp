#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int n;
int arr[35][35];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
struct node{int x, y;};
queue<node> que;

void bfs(){
    que.push((node){0, 0});
    arr[0][0] = -1;
    while(!que.empty()){
        node front = que.front();
        // 连通即可
        for (int i=0; i<4; i++){
            int cx = front.x + dx[i];
            int cy = front.y + dy[i];
            if (cx < 0 || cy < 0 || cx > n+1 || cy > n+1 || arr[cx][cy] == 1 || arr[cx][cy] == -1) continue;
            arr[cx][cy] = -1;
            que.push((node){cx, cy});
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
    bfs();
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            if (arr[i][j] == -1) cout << 0 << " ";
            else if (arr[i][j] == 0) cout << 2 << " ";
            else cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}