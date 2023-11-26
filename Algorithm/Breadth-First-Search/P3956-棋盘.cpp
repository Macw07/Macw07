#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

int m, n;
int arr[105][105];
int vis[105][105];
struct node{
    int x, y;
    int steps;
    bool magic;
    bool friend operator < (node a, node b){
        return a.steps > b.steps;
    }
};
priority_queue<node> que;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

void bfs(){
    que.push((node){1, 1, 0, 1});
    vis[1][1] = 1;
    while(!que.empty()){
        node front = que.top();
        if (front.x == m && front.y == m){
            printf("%d", front.steps);
            return;
        }
        for (int i=0; i<4; i++){
            int cx = front.x + dx[i];
            int cy = front.y + dy[i];
            if (cx < 1 || cy < 1 || cx > m || cy > m || vis[cx][cy]) continue;
            if (arr[cx][cy] == 0 && front.magic == 0) continue;  // 用了魔法，且下一步是空格子，跳过
            vis[cx][cy] = 1;
            if (arr[cx][cy]){
                //颜色一样
                if (arr[front.x][front.y] == arr[cx][cy]) {
                    que.push((node){cx, cy, front.steps, 1});
                }
                // 颜色不一样
                else {
                    que.push((node){cx, cy, front.steps+1, 1});
                }
            } else if (front.magic){  // 可以使用magic
                arr[cx][cy] = arr[front.x][front.y];
                que.push((node){cx, cy, front.steps+2, 0});   
            }
        }
        que.pop();
    }
    cout << -1 << endl;
    return;
}

int main(){
    scanf("%d %d", &m, &n);
    while(n--){
        int x, y, c;
        scanf("%d %d %d", &x, &y, &c);
        arr[x][y] = c + 1;
    }
    bfs();
    return 0;
}