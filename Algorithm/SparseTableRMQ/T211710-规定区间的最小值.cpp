#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

const int MAXN = 1e5 + 5;
int n, m;
int ST[MAXN][20];

int main(){
    scanf("%d %d", &n, &m);
    memset(ST, 0x7f, sizeof ST);
    for (int i=1; i<=n; i++) scanf("%d", &ST[i][0]);
    
    for (int j=1; j<=18; j++){
        for (int i=1; i + (1 << j) - 1 <= n; i++){
            ST[i][j] = min(ST[i][j-1], ST[i + (1 << (j-1))][j-1]);
        }
    }
    
    cout << 0 << endl;
    for (int i=2; i<=n; i++){
        int l = max(1,i-m);
        int r = i-1;
        int k = log2(r - l + 1);
        int ans = min(ST[l][k], ST[r - (1 << k) + 1][k]);
        printf("%d\n", ans);
    }
    
    return 0;
}