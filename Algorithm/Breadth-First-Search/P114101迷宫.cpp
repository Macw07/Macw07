#include <iostream>
#include <queue>
using namespace std;

int n, m;
char map[1005][1005];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int vis[1005][1005];
int arr[10000005]; 
int head = 1;

struct node{
    int x;
    int y;
    char status;
};

queue<node> q;

void bfs(int x, int y){
    int ans = 1;
    vis[x][y] = head;
    q.push((node){x, y, (map[x][y] == '0' ? '0' : '1')});

    while (!q.empty()){
        node t = q.front();
        q.pop();
        for (int i=0; i<4; i++){
            int cx = t.x + dx[i];
            int cy = t.y + dy[i];
            if (cx > n || cy > n || cx < 1 || cy < 1 || vis[cx][cy] || t.status == map[cx][cy]) continue;
            vis[cx][cy] = head; 
            ans++;
            q.push((node){cx, cy, (map[cx][cy] == '0' ? '0' : '1')});
        }
    }

    arr[head++] = ans;
    cout << ans << endl;
    return;
}

int main(){
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            cin >> map[i][j];
        }
    }
    for (int i=0; i<m; i++){
        int m1, m2;
        cin >> m1 >> m2;
        if(vis[m1][m2]){
            cout << arr[vis[m1][m2]] << endl;;
        } else{
            bfs(m1, m2);
        }
    }
    return 0;
}