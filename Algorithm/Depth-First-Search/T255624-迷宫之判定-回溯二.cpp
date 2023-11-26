#include <iostream>
#include <algorithm>
using namespace std;

char map[50][50];
bool vis[50][50], flag = 1;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
int n, m;

// dfs 100%使用递归函数
void dfs(int x, int y){
    if (x == n-1 && y == m-1){
        cout << "YES" << endl;
        flag = 0;
        return ;
    }
    for (int i=0; i<4; i++){
        int cx = x + dx[i];
        int cy = y + dy[i];
        if (cx < 0 || cy < 0 || cx >= n || cy >= m || vis[cx][cy] || map[cx][cy] == '#') continue;
        vis[cx][cy] = 1;
        dfs(cx, cy);
    }
    vis[x][y] = 0;
    return ;
}

int main(){
    cin >> n >> m;
    for (int i=0; i<n; i++){
        cin >> map[i];
    }
    dfs(0, 0);
    if (flag){
        cout << "NO" << endl;
    }
    return 0;
}