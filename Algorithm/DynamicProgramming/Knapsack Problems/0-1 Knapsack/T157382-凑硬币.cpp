#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int n, m;
int arr[25];
int dp[105];

int main(){
    cin >> n >> m;
    for (int i=1; i<=n; i++){
        cin >> arr[i];
    }
    memset(dp, 0x7f, sizeof dp);
    dp[0] = 0;
    for (int i=1; i<=n; i++){
        for (int j=0; j<=m; j++){
            if (j >= arr[i]){
                dp[j] = min(dp[j], dp[j-arr[i]]+1);
            }
        }
    }
    cout << dp[m] << endl;
    return 0;
}