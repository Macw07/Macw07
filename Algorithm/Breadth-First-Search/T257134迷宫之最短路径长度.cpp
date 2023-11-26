#include <iostream>
#include <queue>
using namespace std;

int n, m;
char arr[500][500];
int vis[500][500];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
struct dimension{
    int x;
    int y;
    int steps;
};
queue<dimension> q;

int main(){
    cin >> n >> m;
    for (int i=1; i<=n; i++){
        string s;
        cin >> s;
        for (int j=1; j<=m; j++){
            arr[i][j] = s[j-1];
        }
    }

    // Breadth First Search
    dimension d = {1, 1, 0};
    vis[1][1] = 1;
    q.push(d);

    while(!q.empty()){
        // End Conditions
        if (q.front().x == n && q.front().y == m){
            cout << q.front().steps;
            return 0;
        }
        for (int i=0; i<4; i++){
            int cx = q.front().x + dx[i];
            int cy = q.front().y + dy[i];
            if (cx > n || cy > m || cx < 1 || cy < 1) continue;
            if (arr[cx][cy] != '#' && vis[cx][cy] == 0){
                vis[cx][cy] = 1;
                dimension temp = {cx, cy, q.front().steps+1};
                q.push(temp);
            }
        }
        q.pop();
    }
    cout << -1 << endl;
    return 0;
}