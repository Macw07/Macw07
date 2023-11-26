#include <iostream>
using namespace std;

int arr[1005] = {};
int dp[1005] = {};

int main(){
    int n;
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> arr[i];
    }
    dp[0] = arr[0];
    dp[1] = max(arr[0], arr[1]);
    for (int i=2; i<=n; i++){
        dp[i] = max(dp[i-1], dp[i-2]+arr[i]);
    }
    cout << dp[n];
    return 0;
}