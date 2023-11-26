#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int n, m, a, b;
int arr[505][505];
int vis[505][505];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
struct node{
    int x;
    int y;
    int steps;
};
queue<node> que;
queue<node> leader;

void bfs(){
    while(!que.empty()){
        node front = que.front();
        if (arr[front.x][front.y] == -2){
            arr[front.x][front.y] = front.steps;
        }
        for (int i=0; i<4; i++){
            int cx = front.x + dx[i];
            int cy = front.y + dy[i];
            if (cx < 1 || cy < 1 || cx > n || cy > m || vis[cx][cy]) continue;
            que.push((node){cx, cy, front.steps+1});
            vis[cx][cy] = 1;
        }
        que.pop();
    }
    return;
}

int main(){
    cin >> n >> m >> a >> b;
    for (int i=0; i<a; i++){
        int x, y;
        cin >> x >> y;
        que.push((node){x, y, 0});
        vis[x][y] = 1;
        arr[x][y] = -1;
    }
    for (int i=0; i<b; i++){
        int x, y;
        cin >> x >> y;
        arr[x][y] = -2;
        leader.push((node){x, y, 0});
    }
    bfs();
    while(!leader.empty()){
        cout << arr[leader.front().x][leader.front().y] << endl;
        leader.pop();
    }
    return 0;
}