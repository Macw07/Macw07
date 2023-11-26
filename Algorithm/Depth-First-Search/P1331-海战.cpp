#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

// 我是真的服了这道题了，一开始题目没看清，就直接交上去了。

int n, m, ans;
char arr[1005][1005];
int dx[] = {0, 1, -1, 0};
int dy[] = {1, 0, 0, -1};
int maxn, maxm, minn, minm;

void init(){
    maxn = maxm = -1;
    minn = minm = 0x7f7f7f;
    ans++;
    return ;
}

void check(){
    for (int k=minn; k<=maxn; k++){
        for (int l=minm; l<=maxm; l++){
            if (arr[k][l] != '.') continue;
            printf("Bad placement.\n");
            exit(0);
        }
    }
}

void dfs(int x, int y){
    maxn = max(maxn, x); maxm = max(maxm, y);
    minn = min(minn, x); minm = min(minm, y);
    arr[x][y] = '*';
    for (int i=0; i<4; i++){
        int cx = x + dx[i];
        int cy = y + dy[i];
        if (cx < 0 || cy < 0 || cx >= n || cy >= m || arr[cx][cy] != '#') continue;
        dfs(cx, cy);
    }
    return ;
}

int main(){
    cin >> n >> m;
    for (int i=0; i<n; i++) cin >> arr[i];
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            if (arr[i][j] != '#') continue;
            init(), dfs(i, j), check();
        }
    }
    printf("There are %d ships.\n", ans);
    return 0;
}