#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN = 5e4 + 5;
int n, m, t, l, r;
int ST_max[MAXN][20];
int ST_min[MAXN][20];

void RMQ_MAX(){
    for (int j=1; j<=17; j++){
        for (int i=1; i + (1 << j) - 1 <= n; i++){
            ST_max[i][j] = max(ST_max[i][j-1], ST_max[i + (1 << (j-1))][j-1]);
        }
    }
    return ;
}

void RMQ_MIN(){
    for (int j=1; j<=17; j++){
        for (int i=1; i + (1 << j) - 1 <= n; i++){
            ST_min[i][j] = min(ST_min[i][j-1], ST_min[i + (1 << (j-1))][j-1]);
        }
    }
}

int main(){
    scanf("%d %d", &n, &m);
    memset(ST_min, 0x7f, sizeof ST_min);
    for (int i=1; i<=n; i++){
        scanf("%d", &t);
        ST_max[i][0] = ST_min[i][0] = t;
    }
    RMQ_MAX();
    RMQ_MIN();
    while(m--){
        scanf("%d %d", &l, &r);
        int k = log2(r - l + 1);
        int maxi = max(ST_max[l][k], ST_max[r - (1 << k) + 1][k]);
        int mini = min(ST_min[l][k], ST_min[r - (1 << k) + 1][k]);
        printf("%d\n", maxi - mini);
    }
    return 0;
}