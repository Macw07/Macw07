#include <iostream>
#include <algorithm>
using namespace std;

int n;
long long dp[10005];
int nums[10005], ptr = 1;

bool isPrime(int k){
    for (int i=2; i*i<=k; i++){
        if (k % i == 0) return false;
    }
    return true;
}

int main(){
    cin >> n;
    for (int i=2; i<=n; i++){
        if (isPrime(i)){
            nums[ptr++] = i;
        }
    }
    dp[0] = 1;
    for (int i=1; i<ptr; i++){
        for (int j=0; j<=n; j++){
            if (j >= nums[i]){
                dp[j] += dp[j-nums[i]];
            }
        }
    }
    cout << dp[n] << endl;
    return 0;
}