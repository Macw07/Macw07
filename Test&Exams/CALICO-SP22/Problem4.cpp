#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int t, n, m, len, flag;
string origin;
char map[305][305];
int ans[305][305];
int dx[] = {0, 1, -1, 0};
int dy[] = {1, 0, 0, -1};

void setANS(int x, int y, int k, int dir){
    if (k == len) return ;
    ans[x][y] = 1;
    int cx = x + dx[dir];
    int cy = y + dy[dir];
    setANS(cx, cy, k+1, dir);
    return ;
}

void dfs(int x, int y, int k, int dir, int bg, int ed){
    if (k == len){
        flag = 1;
        setANS(bg, ed, 0, dir);
        return ;
    }
    if (map[x][y] != origin[k]) return ;
    int cx = x + dx[dir];
    int cy = y + dy[dir];
    dfs(cx, cy, k+1, dir, bg, ed);
    return ;
}


int main(){
    cin >> t;
    while(t--){
        cin >> origin;
        len = origin.size();
        cin >> n >> m;
        memset(ans, 0, sizeof ans);

        for (int i=1; i<=n; i++){
            for (int j=1; j<=m; j++){
                cin >> map[i][j];
            }
        }

        for (int i=1; i<=n; i++){
            for (int j=1; j<=m; j++){
                if (map[i][j] == origin[0]) {
                    for (int k=0; k<4; k++){
                        flag = 0;
                        dfs(i, j, 0, k, i, j);
                    }
                }
            }
        }

        for (int i=1; i<=n; i++){
            for (int j=1; j<=m; j++){
                if (ans[i][j]) cout << map[i][j];
                else cout << "#";
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}