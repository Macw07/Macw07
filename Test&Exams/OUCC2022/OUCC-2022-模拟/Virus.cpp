#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

/*
3 4
SWWW
SEWN
EEEN
*/

int n, m, ans;
char arr[1005][1005];
int vis[1005][1005];


int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

struct node{int x, y;};
queue<node> que;

void clear(){
    while(que.size()){
        node t = que.front();
        vis[t.x][t.y] = 1;
        que.pop();
    }
    return ;
}

int direction(char dir){
    if (dir == 'N') return 0;
    if (dir == 'E') return 1;
    if (dir == 'S') return 2;
    if (dir == 'W') return 3;
    return -1;
}

int dfs(int x, int y, int dir){
    vis[x][y] = 2;
    que.push((node){x, y});
    int new_x = x + dx[dir];
    int new_y = y + dy[dir];
    if (new_x <= 0 || new_y <= 0 || new_x > n || new_y > m || vis[new_x][new_y] == 2) return 1;
    if (vis[new_x][new_y] == 1) return 0;
   
    return dfs(new_x, new_y, direction(arr[new_x][new_y]));
}

int main(){
    cin >> n >> m;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            cin >> arr[i][j];
        }
    }
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            if (vis[i][j]) continue;
            ans += dfs(i, j, direction(arr[i][j]));
            clear();
        }
    }
    cout << ans << endl;
    return 0;
}