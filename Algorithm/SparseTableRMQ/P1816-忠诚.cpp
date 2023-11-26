#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN = 1e5 + 5;
int n, m, l, r;
int ST[MAXN][20];

int main(){
    scanf("%d %d", &n, &m);
    memset(ST, 0x7f, sizeof ST);
    for (int i=1; i<=n; i++) scanf("%d", &ST[i][0]);

    for (int j=1; j<=17; j++){
        for (int i=1; i + (1 << j) - 1 <= n; i++){
            ST[i][j] = min(ST[i][j-1], ST[i + (1 << (j-1))][j-1]);
        }
    }

    while(m--){
        scanf("%d %d", &l, &r);
        int k = log2(r - l + 1);
        int ans = min(ST[l][k], ST[r - (1 << k) + 1][k]);
        printf("%d ", ans);
    }

    return 0;
}