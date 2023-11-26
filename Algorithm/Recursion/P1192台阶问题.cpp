#include <iostream>
using namespace std;

int n, k;
long long temp=0;
long long dp[100005];

int main(){
    cin >> n >> k;
    dp[0] = dp[1] = 1;
    for (int i=2; i<=n; i++){
        if (i <= k){
            dp[i] = (dp[i-1]*2)%100003;
        } else{
            dp[i] = (dp[i-1]*2 - dp[i-k-1])%100003;
        }
    }
    temp = (dp[n]+100003)%100003;
    cout << temp;
    return 0;
}