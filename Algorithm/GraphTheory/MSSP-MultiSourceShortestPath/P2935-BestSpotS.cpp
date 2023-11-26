#include <iostream>
#include <algorithm>
using namespace std;

int p, f, c;
int arr[505];
long long dp[8005][8005];

void floyd(){
    for (int k=1; k<=p; k++){
        for (int i=1; i<=p; i++){
            for (int j=1; j<=p; j++){
                if (i == j && j == k) continue;
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }
}

int main(){
    scanf("%d %d %d", &p, &f, &c);
    for (int i=1; i<=p; i++){
        for (int j=1; j<=p; j++){
            dp[i][j] = 0x7f7f7f7f;
        }
        dp[i][i] = 0;
    }
    for (int i=1; i<=f; i++) scanf("%d", &arr[i]);
    for (int j=1; j<=c; j++){
        int v1, v2, w;
        scanf("%d %d %d", &v1, &v2, &w);
        dp[v1][v2] = w;
        dp[v2][v1] = w;
    }
    floyd();
    int t = 0, ans = 0x7f7f7f;
    for (int i=1; i<=p; i++){
        int sum = 0;
        for (int j=1; j<=f; j++){
            sum += dp[i][arr[j]];
        }   
        if (sum < ans){
            t = i;
            ans = sum;
        }
    }
    printf("%d\n", t);
    return 0;
}