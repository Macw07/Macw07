#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int n, m;
int arr[205][205];
int memo[205][205];

int dfs(int x, int y){
    if (memo[x][y] != 0x7f7f7f7f) return memo[x][y];
    if (x < 1) return 0;
    int t1 = 0, t2 = 0, t3 = 0;
    if (y-1 >= 1) t1 = dfs(x-1, y-1);
    t2 = dfs(x-1, y);
    if (y+1 <= m) t3 = dfs(x-1, y+1);
    return memo[x][y] = max(t1, max(t2, t3)) + arr[x][y];
}

int main(){
    cin >> n >> m;
    memset(memo, 0x7f, sizeof memo);
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            cin >> arr[i][j];
        }
    }
    cout << dfs(n+1, m/2+1) << endl;
    return 0;
}