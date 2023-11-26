#include <iostream>
using namespace std;

// 这道题是典型的01背包问题
// S代表着背包的大小
// 约数之合是物品的价值
// 不超过S的值是物品的重量

int dp[1005], v[1005];

// 算约数之和
int fact(int n){
    int sum = 0;
    for (int i=1; i<n; i++){  // 求约数的时候记得把1给算上
        if (n % i == 0) sum += i;
    }
    return sum;
}

int main(){
    int n;
    cin >> n;
    for (int i=1; i<=n; i++){
        v[i] = fact(i);
    }
    // 01背包问题的解决
    for (int i=1; i<=n; i++){
        for (int j=n; j>=i; j--){  // 如果重量比“weight[i]”大的时候
            dp[j] = max(dp[j], dp[j-i]+v[i]);
        }
    }
    cout << dp[n];
    return 0;
}