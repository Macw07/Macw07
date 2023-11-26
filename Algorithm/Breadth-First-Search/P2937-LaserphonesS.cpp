#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

// 本质上题目就是问你需要拐几个弯

int ans = 0x7f7f7f7f;
int n, m;
int sx, sy, fx, fy;
char arr[105][105];
int vis[105][105];  // 记录的是到这位点的时候最少需要turn的次数
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
struct node{
    int x, y;
    int status;
    int turns;
};
queue<node> que;

void bfs(){
    while(!que.empty()){
        node front = que.front();
        if (front.x == fx && front.y == fy){
            // 不断存储最佳答案，直到答案正确为止
            ans = min(ans, front.turns);
        }
        for (int i=0; i<4; i++){
            int cx = front.x + dx[i];
            int cy = front.y + dy[i];
            int step;
            if (cx < 1 || cy < 1 || cx > n || cy > m || arr[cx][cy] == '*') continue;
            // 如果不转弯
            if (front.status == i || front.status == -1){
                step = front.turns;
            } else{  // 如果转弯
                step = front.turns + 1;
            }
            if (vis[cx][cy] < step) continue;
            que.push((node){cx, cy, i, step});
            vis[cx][cy] = step;            
        }
        que.pop();
    }
    return;
}
int main(){
    memset(vis, 0x7f, sizeof vis);
    scanf("%d %d", &m, &n);
    bool flag = 1;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            cin >> arr[i][j];
            if (arr[i][j] == 'C' && flag){
                sx = i;
                sy = j;
                flag = 0;
            } else if (arr[i][j] == 'C'){
                fx = i;
                fy = j;
            }
        }
    }
    que.push((node){sx, sy, -1, 0});
    bfs();
    cout << ans << endl;
    return 0;
}