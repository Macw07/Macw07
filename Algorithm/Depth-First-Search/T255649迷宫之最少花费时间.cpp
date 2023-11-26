#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int startx, starty;
int endx, endy;
int ans = 0x7f7f7f;
char arr[25][25];
int vis[25][25];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

void dfs(int x, int y, int time){
    if (x == endx && y == endy){
        ans = min(ans, time);
        return;
    } 
    // 遍历四个方向
    for (int i=0; i<4; i++){
        int cx = x+dx[i], cy = y+dy[i];
        // 判断是否有障碍
        if (vis[cx][cy] == 0 && arr[cx][cy] == '-' || arr[cx][cy] == 'W'){
            vis[cx][cy] = 1;     
            dfs(cx, cy, time+1);
            vis[cx][cy] = 0;
        } else if (vis[cx][cy] == 0 && arr[cx][cy] >= '1' && arr[cx][cy] <= '9'){
            vis[cx][cy] = 1;     
            int gtime = arr[cx][cy]-'0';
            dfs(cx, cy, time+gtime+1);
            vis[cx][cy] = 0;
        } 
    } 
    return; 
}

int main(){
    cin >> n >> m;
    for (int i=1; i<=n; i++){
        string s;
        cin >> s;
        // 读入数据,找出入口和出口s
        for (int j=1; j<=m; j++){
            // if (s[j-1] == 'Z'){
            //     startx = i, starty = j;
            // } else if (s[j-1] == 'W'){
            //     endx = i, endy = j;
            // }
            arr[i][j] = s[j-1];
        }
    }
    endx = 40, endy = 40;
    // cout << endx << " " << endy << endl;
    dfs(0, 0, 0);
    if (ans == 0x7f7f7f){
        cout << "IMPOSSIBLE" << endl;
    } else {
        cout << ans << endl;
    }
    return 0;
}