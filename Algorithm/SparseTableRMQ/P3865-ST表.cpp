#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

const int MAXN = 1e5+5;
int n, m, l, r;
int ST[MAXN][20];
/*
    ST表运用了倍增的思想来在O(1)时间复杂度内求区间最值。
    ST[i][j] 表示区间[arr[i], arr[i+2^j-1]]的区间最值。
*/

void preprocessing(){
    // 类似于区间动归，先枚举每一个区间的长度，再枚举每一个位置。
    for (int j=1; j<=20; j++){
        for (int i=1; i + (1 << j) - 1 <= n; i++){
            ST[i][j] = max(ST[i][j-1], ST[i + (1 << (j-1))][j-1]);
        }
    }
    return ;
}

int main(){
    scanf("%d %d", &n, &m);
    for (int i=1; i<=n; i++) scanf("%d", &ST[i][0]);
    preprocessing();
    while(m--){
        scanf("%d %d", &l, &r);
        int s = log2(r - l + 1);
        printf("%d\n", max(ST[l][s], ST[r - (1 << s) + 1][s]));
    }
    return 0;
}