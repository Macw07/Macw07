// #include <iostream>
// #include <algorithm>
// using namespace std;

// int ans = 0, temp;
// int n, m;
// int arr[35][35];
// bool vis[35][35];
// int dx[] = {0, 1, 0, -1};
// int dy[] = {1, 0, -1, 0};

// // 通过dfs求连通分量
// void dfs(int x, int y){
//     int cnt = 0;
//     for (int i=0; i<4; i++){
//         int cx = x + dx[i];
//         int cy = y + dy[i];
//         if (cx < 1 || cy < 1 || cx > n || cy > m || arr[cx][cy]) continue;
//         cnt++;
//         if (vis[cx][cy]) continue;
//         temp++;
//         vis[cx][cy] = 1;
//         dfs(cx, cy);
//     }
//     // 每个点必须要有两个相邻的点才算矩形。
//     if (cnt < 2) temp--;
//     return;
// }

// int main(){
//     scanf("%d %d", &n, &m);
//     for (int i=1; i<=n; i++){
//         for (int j=1; j<=m; j++){
//             scanf("%d", &arr[i][j]);
//         }
//     }
//     // 求出最大连通分量
//     for (int i=1; i<=n; i++){
//         for (int j=1; j<=m; j++){
//             if (arr[i][j] == 0){
//                 temp = 1;
//                 vis[i][j] = 1;
//                 dfs(i, j);
//                 ans = max(ans, temp);
//             }
//         }
//     }
//     printf("%d\n", ans);
//     return 0;
// }

// 尝试通过暴力的方法进行解决
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int n, m, temp=0;
int arr[35][35];
int ans = 0;

void check(int x1, int y1, int x2, int y2){
    // 大小的测算，提前先排除部分
    int size = abs(x2-x1)*abs(y2-y1);
    for (int i=x1; i<=x2; i++){
        for (int j=y1; j<=y2; j++){
            if (arr[i][j] == 1) return;
            temp++;
        }
    }
    ans = max(ans, temp);
    return;
}

int main(){
    scanf("%d %d", &n, &m);
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            scanf("%d", &arr[i][j]);
        }
    }
    // 遍历：取两个点分别为i和j。然后进行验证结果。
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            if (arr[i][j] == 1) continue;
            for (int k=i; k<=n; k++){
                for (int l=j; l<=m; l++){
                    if (arr[k][l] == 1) continue;
                    // 遍历出了所有的正方形，然后进行判断即可。
                    temp = 0;
                    check(i, j, k, l);
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
