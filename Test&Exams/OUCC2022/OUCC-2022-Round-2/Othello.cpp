#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

char arr[10][10];
int vis[10][10];
string str;
char target;
int ans, a2;
int ax, ay;
int dx[] = {1, 0, -1, 0, 1, 1, -1, -1};
int dy[] = {0, 1, 0, -1, 1, -1, 1, -1};

void dfs(int x, int y, int steps){
    ans = max(ans, steps);
    for (int i=0; i<8; i++){
        int cx = x + dx[i];
        int cy = y + dy[i];
        if (cx < 1 || cy < 1 || cx > 8 || cy > 8 || vis[cx][cy]) continue;
        if (arr[cx][cy] == target){
            vis[cx][cy] = 1;
            dfs(cx, cy, steps + 1);
        }
    }
    return ;
}

int main(){
    for (int i=1; i<=8; i++){
        for (int j=1; j<=8; j++){
            cin >> arr[i][j];
        }
    }
    cin >> str;
    if (str == "white"){
        target = 'b';
    } else target = 'w';

    for (int i=1; i<=8; i++){
        for (int j=1; j<=8; j++){
            if (arr[i][j] == '0'){
                memset(vis, 10, 10);
                dfs(i, j, 0);
                if (ans > a2){
                    ans = 0;
                    a2 = ans;
                    ax = i, ay = j;
                }
            }
        }
    }
    cout << ay << "," << 8 - ax << endl;
    return 0;
}