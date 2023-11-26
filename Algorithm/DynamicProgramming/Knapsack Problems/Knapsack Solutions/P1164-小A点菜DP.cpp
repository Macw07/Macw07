#include <iostream>
using namespace std;

int m, n;
int arr[105];
int dp[10005];

int main(){
    scanf("%d %d", &n, &m);
    for (int i=1; i<=n; i++){
        scanf("%d", &arr[i]);
    }
    dp[0] = 1;
    for (int i=1; i<=n; i++){
        for (int j=m; j>=0; j--){
            if (j >= arr[i]){
                dp[j] += dp[j-arr[i]];
            }
        }
    }
    cout << dp[m] << endl;
    return 0;
}