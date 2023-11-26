#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

int n, m;
char arr[1005][1005];
int vis[1005][1005];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int s1, t1, s2, t2, s3, t3;

struct node{
    int x, y;
    int steps;
};

int bfs(int s1, int t1, int s2, int t2){
    queue<node> que;
    que.push((node){s1, t1, 0});
    vis[s1][t1] = 1;

    while(!que.empty()){
        node t = que.front();
        que.pop();
        if (t.x == s2 && t.y == t2){
            return t.steps;
        }
        for (int i=0; i<4; i++){
            int cx = dx[i] + t.x;
            int cy = dy[i] + t.y;
            
            if (cx < 1 || cy < 1 || cx > n || cy > m || vis[cx][cy] || arr[cx][cy] == '#') continue;
            vis[cx][cy] = 1;
            que.push((node){cx, cy, t.steps + 1});
        }
    }
    return -1;
}

int main(){
    // freopen("9.in", "r", stdin);
    cin >> n >> m;
    for (int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin >> arr[i][j];
        }
    }
    cin >> s1 >> t1 >> s2 >> t2 >> s3 >> t3;
    if (arr[s2][t2] == '#' || arr[s3][t3] == '#'){
        cout << -1 << endl;
        return 0;
    }
    
    int a = bfs(s1, t1, s3, t3);
    if (a == -1) {
        cout << -1 << endl;
        return 0;
    }
    memset(vis, 0, sizeof vis);
    int b = bfs(s3, t3, s2, t2);
    if (b == -1) {
        cout << -1 << endl;
        return 0;
    }
    cout << a + b << endl;
    return 0;
}