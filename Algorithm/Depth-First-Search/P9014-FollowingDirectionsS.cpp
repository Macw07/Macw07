#include <iostream>
#include <algorithm>
using namespace std;

char c;
int n, t, cx, cy;
int arr[1505][1505];
int cnt[1505][1505];

inline int ans(){
    int ans = 0;
    for (int i=1; i<=n; i++){
        ans += max(0, (cnt[i][n+1]-1)) * arr[i][n+1] + max(0, (cnt[n+1][i]-1)) * arr[n+1][i];
    }
    return ans;
}

inline void dfs(int x, int y, int sum){
    if (x == 0 || y == 0) return ;
    cnt[x][y] = 1;
    if (arr[x-1][y] == 2) {
        dfs(x-1, y, sum);
        cnt[x][y] = cnt[x-1][y] + 1;
    }
    if (arr[x][y-1] == 1) {
        dfs(x, y-1, sum);
        cnt[x][y] = cnt[x][y-1] + 1;
    }
    return ;
}

inline void dfs_new(int x, int y, int change, int status){
    if (status != 1) cnt[x][y] += change;
    if (x == n + 1 || y == n + 1) return ;
    if (arr[x][y] == 1) dfs_new(x, y+1, change, 0);
    else dfs_new(x+1, y, change, 0);
    return ;
}

int main(){
    scanf("%d", &n);

    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            cin >> c;
            if (c == 'R') arr[i][j] = 1;
            else arr[i][j] = 2;
        }
        scanf("%d", &arr[i][n+1]);
    }

    for (int i=1; i<=n; i++) scanf("%d", &arr[n+1][i]);

    for (int i=1; i<=n; i++){
        if (arr[i][n] == 1) dfs(i, n+1, arr[i][n+1]);
        if (arr[n][i] == 2) dfs(n+1, i, arr[n+1][i]);
    }

    printf("%d\n", ans());

    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &cx, &cy);
        dfs_new(cx, cy, -cnt[cx][cy], 1);
        arr[cx][cy] = 3 - arr[cx][cy];
        dfs_new(cx, cy, cnt[cx][cy], 1);
        printf("%d\n", ans());
    }
    return 0;
}