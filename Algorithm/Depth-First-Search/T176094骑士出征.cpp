#include <iostream>
using namespace std;

int ans = 0;
int n, m;
int arr[35][35];
int dx[] = {-2, -1, 2, 1};
int dy[] = {1, 2, 1, 2};


void dfs(int x, int y){
    if (x == n && y == m){
        ans++;
        return;
    }
    for (int i=0; i<4; i++){
        int cx = x+dx[i];
        int cy = y+dy[i];
        if (x > n || y > m || x < 1 || y < 1) continue;
        dfs(cx, cy);
    }
    return;
}

int main(){
    cin >> n >> m;
    dfs(1, 1);
    cout << ans << endl;
    return 0;
}