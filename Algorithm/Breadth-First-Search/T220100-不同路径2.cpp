#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int ans = 0;
int n, m;
int arr[55][55];

void dfs(int x, int y){
    if (x == n && y == m){
        ans += 1;
        return ;
    }
    if (arr[x+1][y] == 0) dfs(x+1, y);
    if (arr[x][y+1] == 0) dfs(x, y+1);
    return ;
}

int main(){
    cin >> n >> m;
    memset(arr, 1, sizeof arr);
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            cin >> arr[i][j];
        }
    }
    dfs(1, 1);
    cout << ans << endl;
    return 0;
}