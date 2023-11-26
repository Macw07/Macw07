#include <iostream>
#include <queue>
using namespace std;

struct node{
    int x;
    int y;
    int steps;
};

int n, m;
char arr[50][50];
int vis[50][50];
queue<node> q;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int main(){
    cin >> n >> m;
    for (int i=1; i<=n; i++){
        string s;
        cin >> s;
        for (int j=1; j<=m; j++){
            arr[i][j] = s[j-1];
        }
    }
    // BFS
    q.push((node){1, 1, 1});
    vis[1][1] = 1;
    while(!q.empty()){
        node t = q.front();
        if (t.x == n && t.y == m){
            cout << t.steps << endl;
            break;
        }
        for (int i=0; i<4; i++){
            int cx = t.x + dx[i];
            int cy = t.y + dy[i];
            if (cx > n || cy > m || cx < 1 || cy < 1 || vis[cx][cy] == 1 || arr[cx][cy] == '#') continue;
            vis[cx][cy] = 1;
            q.push((node){cx, cy, t.steps+1});
        }
        q.pop();
    }
    return 0;
}