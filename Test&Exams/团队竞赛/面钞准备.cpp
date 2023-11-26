#include <iostream>
#include <cstring>
using namespace std;

int n;
int arr[] = {0, 1, 5, 11};
int dp[2000005];

int main(){
    cin >> n;
    for (int i=1; i<=n; i++){
        if (i < 5) dp[i] = i;
        else if (i < 11)  dp[i] = min(dp[i-5], dp[i-1]) + 1;
        else dp[i] = min(dp[i-1], min(dp[i-5], dp[i-11])) + 1;
    }
    cout << dp[n] << endl;
    return 0;
}