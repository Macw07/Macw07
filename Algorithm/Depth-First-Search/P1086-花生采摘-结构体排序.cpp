#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int arr[25][25];
int n, m, k, ans, ptr = 0, ptr2 = 0;

struct coordinate{int x, y, value;};
coordinate peanuts[800];

bool cmp(coordinate c1, coordinate c2){
    return c1.value > c2.value;
}

void dfs(int x, int y, int nx, int ny, int amount, int steps){
    // 判断是否来得及
    int go = abs(nx-x) + abs(ny-y);
    int times = go + nx + 1;
    if (times+steps > k) return ;  // 回不去了
    ptr2 += 1;
    coordinate next = peanuts[ptr2];
    ans = max(ans, amount + arr[nx][ny]);
    dfs(nx, ny, next.x, next.y, amount + arr[nx][ny], steps + times - nx);
}

int main(){
    cin >> n >> m >> k;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            cin >> arr[i][j];
            if (arr[i][j]){
                peanuts[ptr++] = (coordinate){i, j, arr[i][j]};
            }
        }
    }
    sort(peanuts, peanuts + ptr, cmp);
    dfs(0, peanuts[ptr2].y, peanuts[ptr2].x, peanuts[ptr2].y, 0, 0);
    cout << ans << endl;
    return 0;
}