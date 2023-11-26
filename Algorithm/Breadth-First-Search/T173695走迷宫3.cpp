#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int n, m;
int sx, sy;
char arr[50][50];
int vis[50][50];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int ans = 0x7f7f7f;

struct node{
    int x;
    int y;
    int steps;
    bool friend operator < (node a,node b){
		return a.steps>b.steps;//>表示step从小到排 
	}
};
priority_queue<node> q;

int main(){
    cin >> n >> m;
    for (int i=1; i<=n; i++){
        string s;
        cin >> s;
        for (int j=1; j<=m; j++){
            arr[i][j] = s[j-1];
            if (arr[i][j] == 'Z'){
                sx = i;
                sy = j;
            }
        }
    }

    // BFS
    node f = {sx, sy, 0};
    q.push(f);
    vis[sx][sy] = 1;
    
    while(!q.empty()){
        int x = q.top().x;
        int y = q.top().y;
        int steps = q.top().steps;
        if (arr[x][y] == 'W'){
            // cout << "YES" << endl;
            ans = min(ans, steps);
        }
        for (int i=0; i<4; i++){
            int cx = x + dx[i];
            int cy = y + dy[i];
            if (cx > n || cy > m || cx < 1 || cy < 1 || vis[cx][cy] == 1 || arr[cx][cy] == '#') continue;
            vis[cx][cy] = 1;
            node temp = {cx, cy, steps+1};
            // printf("%d %d %d\n", cx, cy, steps+1);
            if (arr[cx][cy] >= '1' && arr[cx][cy] <= '9'){
                // cout << arr[cx][cy] << endl;
                temp.steps += arr[cx][cy]-'0';
            } 
            q.push(temp);
        }
        q.pop();
    }
    if (ans == 0x7f7f7f){
        cout << "IMPOSSIBLE" << endl;
    } else{
        cout << ans << endl;
    }
    return 0;
}