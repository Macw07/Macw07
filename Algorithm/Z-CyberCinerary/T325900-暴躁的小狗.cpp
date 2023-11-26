#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

/*
早知道就提早使用平行四边形法则了。
我居然忘记了会有向量加法这种东西，该死。
*/

int n, m, k;
int arr[105][105];
// 四个方向：上、右、下、左
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
// Cindy攻击的相对方向
int dc[] = {3, 4, 1, 2};

struct node{
    int x;
    int y;
    int steps;
};

struct dimension{
    int x;
    int y;
};

queue<node> que;

void dfs(int x, int y, int steps){
    // 判断递归的结束条件，当四周都没有Cindy时，结束
    bool flag = true;
    int Cindys = 0;  // Cindy的数量
    // NTs的四个方向（上、右、下、左），是否有正要攻击的Cindy
    int attack[5] = {};

    for (int i=0; i<4; i++){
        int cx = x + dx[i];
        int cy = y + dy[i];
        if (arr[cx][cy] && (arr[cx][cy] + steps)%4 == dc[i]) {
            attack[i] = 1;
            Cindys += 1;
            flag = false;
        }
    }
    if (flag) return;

    // 只有一个Cindy的情况下
    if (Cindys == 1){
        for (int i=0; i<4; i++){
            if (attack[i] == 1){
                dfs(-x, -y, steps);
                break;
            }
        }
    }

    // 两个Cindy的情况下
    bool control = false;
    if (Cindys == 2){
        for (int i=0; i<3; i++){
            if (control) break;
            for (int j=1; j<4-i; j++){
                if (attack[i] == 0 || attack[j] == 0 || i == j) continue;
                // 如果两个Cindy面对面
                if (abs(i-j) == 2) {
                    control = 1;
                    break;
                }
                // 如果两个Cindy在一起
                int cx = x + dx[i] + dx[j];
                int cy = y + dy[i] + dy[j];
                if (cx < 1 || cy < 1 || cx > n || cy > m || arr[cx][cy]) continue;
                dfs(cx, cy, steps);
            }
        }
    }

    // 三个Cindy的情况下

    return ;
}

void bfs(){
    while(que.size()){
        node top = que.front();
        if (top.x == n && top.y == m){
            cout << top.steps << endl;
            return ;
        }
        for (int i=0; i<4; i++){
            int cx = top.x + dx[i];
            int cy = top.y + dy[i];
            if (cx < 1 || cy < 1 || cx > n || cy > m || arr[cx][cy]) continue;
            // 超级大模拟 - 模拟被Cindy弹飞
            // check(cx, cy, top.steps+1);
        }
        que.pop();
    }
    return ;
}

int main(){
    scanf("%d %d %d", &n, &m, &k);
    for (int i=1; i<=n; i++){
        int x, y, d;
        scanf("%d %d %d", &n, &y, &d);
        arr[x][y] = d;
    }
    que.push((node){1, 1, 0});
    bfs();
    return 0;
}