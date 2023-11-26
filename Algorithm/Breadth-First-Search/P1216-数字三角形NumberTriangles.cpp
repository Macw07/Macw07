#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int n, ans = 0;
int arr[1005][1005];
int memo[1005][1005];

int dfs(int x, int y){
    if (memo[x][y] >= 0) return memo[x][y];
    if (x == n+1)  return memo[x][y] = 0;
    
    int t1 = 0, t2 = 0;
    t1 = dfs(x+1, y);
    t2 = dfs(x+1, y+1);

    memo[x][y] = max(t1, t2) + arr[x][y];
    return memo[x][y];
}

int main(){
    cin >> n;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=i; j++){
            cin >> arr[i][j];
        }
    }
    memset(memo, -1, sizeof memo);
    cout << dfs(1, 1);
    return 0;
}