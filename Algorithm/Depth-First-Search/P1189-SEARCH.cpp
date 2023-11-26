#include <iostream>
using namespace std;

int n, m, k, cnt;
bool isAccessed;
char arr[55][55];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
int dir[1005], sx, sy;
bool memo[1005][55][55];  // 如果在第k步的时候来到了i,j这个位置，则memo[k][i][j] = 1;

inline int direction(string str){
    if (str == "NORTH") return 2;
    else if (str == "SOUTH") return 0;
    else if (str == "EAST") return 1;
    return 3;  // str == "WEST"
}

void dfs(int x, int y, int forward, int steps){
    if (steps == k + 1){
        arr[x][y] = '*';
        if (x == sx && y == sy) isAccessed = 1;
        return ;
    }

    // 走一步，走两步，...，走i步。
    for (int i=1; ; i++){
        int cx = x + dx[forward] * i;
        int cy = y + dy[forward] * i;
        if (cx < 1 || cy < 1 || cx > n || cy > m) break;
        if (arr[cx][cy] == 'X') break;
        if (memo[steps+1][cx][cy]) continue;
        memo[steps+1][cx][cy] = 1;
        dfs(cx, cy, dir[steps+1], steps + 1);
    }
    return ;
}

int main(){
    // freopen("P1189_2.in", "r", stdin);
    // freopen("P1189_2-2.out", "w", stdout);
    cin >> n >> m;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            cin >> arr[i][j];
            if (arr[i][j] == '*'){
                sx = i; sy = j;
            }
        }
    }
    cin >> k;
    for (int i=1; i<=k; i++){
        string str;
        cin >> str;
        dir[i] = direction(str);
    }

    memo[sx][sy][1] = 1;
    dfs(sx, sy, dir[1], 1);

    if (!isAccessed) arr[sx][sy] = '.';

    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            cout << arr[i][j];
        }
        cout << endl;
    }
    return 0;
}