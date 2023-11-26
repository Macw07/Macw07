#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int n, m, q;
int arr[105][105];
bool check = false;
int a1, b1, a2, b2;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

// 当last为0-3的时候，依照dx，dy走的方向。
void dfs(int x, int y, int last, int swerve){
    if (x == a2 && y == b2){
        // 说明走到了小羊的家
        check = true;
        return;
    }
    if (swerve > 2) return;  // 反正已经拐过两个弯了，没有继续走的意义了。
    // 尝试往四个方向去拐
    for (int i=0; i<4; i++){
        int cx = x + dx[i];
        int cy = y + dy[i];
        if (cx < 1 || cy < 1 || cx > n || cy > m) continue;
        if (arr[cx][cy] == 0 || arr[cx][cy] == arr[a1][b1]){
            if (i == last){
                dfs(cx, cy, i, swerve);
            } else{
                dfs(cx, cy, i, swerve+1);
            }
        }
    }
    return;
}

int main(){
    while(1){
        scanf("%d %d", &n, &m);
        if (n == 0 && m == 0) return 0;
        for (int i=1; i<=n; i++){
            for (int j=1; j<=m; j++){
                scanf("%d", &arr[i][j]);
            }
        }
        scanf("%d", &q);
        while(q--){
            scanf("%d %d %d %d", &a1, &b1, &a2, &b2);
            if (arr[a1][b1] != arr[a2][b2]) {printf("NO\n"); continue;}
            if (arr[a1][b1] == 0 || arr[a2][b2] == 0) {printf("NO\n"); continue;}
            for(int j=0; j<4; j++){
				dfs(a1, b1, j, 0);
                // memset(vis, 0, sizeof vis);
			} 
            if (!check) printf("NO\n");
            else printf("YES\n");
            check = false;
        }
    }
    return 0;
}