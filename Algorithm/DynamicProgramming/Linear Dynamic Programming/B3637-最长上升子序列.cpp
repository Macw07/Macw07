#include <iostream>
using namespace std;

int n;
int arr[5005];
int dp[5005];

int main(){
    scanf("%d", &n);
    for (int i=1; i<=n; i++){
        scanf("%d", &arr[i]);
        dp[i] = 1;
    }
    for (int i=1; i<=n; i++){
        for (int j=1; j<i; j++){
            if (arr[i] > arr[j]){
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    int ans = 0;
    for (int i=1; i<=n; i++){
        ans = max(ans, dp[i]);
    }   
    cout << ans << endl;
    return 0;
}