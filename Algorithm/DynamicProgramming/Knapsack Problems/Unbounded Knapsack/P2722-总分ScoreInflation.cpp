#include <iostream>
#include <algorithm>
using namespace std;

int m, n;
int s[10005], t[10005];
int dp[10005];

int main(){
    scanf("%d %d", &m, &n);
    for (int i=1; i<=n; i++){
        scanf("%d %d", &s[i], &t[i]);
    }
    for (int i=1; i<=n; i++){
        for (int j=0; j<=m; j++){
            if (j - t[i] >= 0){
                dp[j] = max(dp[j], dp[j-t[i]]+s[i]);
            }
        }
    }
    printf("%d\n", dp[m]);
    return 0;
}