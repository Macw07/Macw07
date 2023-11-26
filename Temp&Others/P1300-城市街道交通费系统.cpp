#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

int n, m;
char map[35][35];
int dx[] = {0, 1, -1, 0};
int dy[] = {1, 0, 0, -1};
int memo[35][35];  
int sx, sy, ans = 0x7f7f7f7f;

int direction(char c){
    if (c == 'E') return 0;
    if (c == 'S') return 1;
    if (c == 'N') return 2;
    return 3;
}

bool check(int cx, int cy){
    if (cx < 1 || cy < 1 || cx > n || cy > m) return false;
    return (map[cx][cy] != '.');
}

int check_left(int dir){
    if (dir == 0) return 2;
    if (dir == 1) return 0;
    if (dir == 2) return 3;
    return 1;
}

int check_right(int dir){
    if (dir == 0) return 1;
    if (dir == 1) return 3;
    if (dir == 2) return 0;
    return 2;
}

int check_back(int dir){
    if (dir == 0) return 3;
    if (dir == 1) return 2;
    if (dir == 2) return 1;
    return 0;
}

void dfs(int x, int y, int dir, int cost){
    if (memo[x][y] == 500) return ;
    memo[x][y] += 1;
    
    // cout << x << " " << y << endl;
    if (cost >= ans) return ;
    if (map[x][y] == 'F'){
        ans = min(ans, cost);
        return ;
    }

    // 前进，左转，右转。
    bool flag = true;
    int cx = dx[dir] + x;
    int cy = dy[dir] + y;
   
    if (check(cx, cy)) {
        dfs(cx, cy, dir, cost);
        flag = false;
    }

    int left = check_left(dir); 
    cx = dx[left] + x;
    cy = dy[left] + y;
    if (check(cx, cy)) {
        dfs(x, y, left, cost+1);
        flag = false;
    }

    int right = check_right(dir);
    cx = dx[right] + x;
    cy = dy[right] + y;
    if (check(cx, cy)) {
        dfs(x, y, right, cost+5);
        flag = false;
    }

    // if (flag){
    //     int trd = check_back(dir);
    //     cx = dx[trd] + x;
    //     cy = dy[trd] + y;
    //     if (check(cx, cy)) dfs(x, y, trd, cost+10);
    // }

    return ;
}

int main(){
    cin >> n >> m;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            cin >> map[i][j];
            if (map[i][j] == 'N' || map[i][j] == 'W' 
            || map[i][j] == 'E' || map[i][j] == 'S'){
                sx = i;
                sy = j;
            } 
        }
    }
    memset(memo, -1, sizeof memo);
    dfs(sx, sy, direction(map[sx][sy]), 0);
    cout << ans << endl;
    return 0;
}