#include <iostream>
#include <algorithm>
using namespace std;

int n, m, a, b, c;
int arr[55][55];
int dx[] = {0, 1, -1, 0};
int dy[] = {1, 0, 0, -1};

void dfs(int x, int y, int color, int new_color){
    arr[x][y] = new_color;
    for (int i=0; i<4; i++){
        int cx = x + dx[i];
        int cy = y + dy[i];
        if (cx < 1 || cy < 1 || cx > n || cy > m || arr[cx][cy] != color) continue;
        arr[cx][cy] = new_color;
        dfs(cx, cy, color, new_color);
    }
    return ;
}

int main(){
    cin >> n >> m;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            cin >> arr[i][j];
        }
    }
    cin >> a >> b >> c;
    dfs(a, b, arr[a][b], c);
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            cout << arr[i][j] << ' ';
        } cout << endl;
    }
    return 0;
}