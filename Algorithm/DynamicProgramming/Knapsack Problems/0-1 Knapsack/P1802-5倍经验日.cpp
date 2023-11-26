#include <iostream>
using namespace std;

// 这道题要开 long long

long long n, x;
long long dp[1005];
long long wins[1005], loses[1005], medicines[1005];

long long max(long long a, long long b){
    if (a > b){
        return a;
    }
    return b;
}

int main(){
    cin >> n >> x;
    for (int i=1; i<=n; i++){
        cin >> loses[i] >> wins[i] >> medicines[i];
    }
    // 01 背包模板题目：用不用药
    for (int i=1; i<=n; i++){
        for (int j=x; j>=0; j--){
            int p1 = 0;
            if (j >= medicines[i]) p1 = dp[j-medicines[i]]+wins[i];
            p1 = max(p1, dp[j]+loses[i]);
            dp[j] = max(p1, dp[j]);
        }
    }
    cout << 5*dp[x] << endl;
    return 0;
}