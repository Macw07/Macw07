#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

int main()
{
    fastio;
    int n;
    cin >> n;
    vector<int> dp(n + 1, n - 1);
    dp[1] = 0;
    for (int i = 1; i < n; i++)
    {
        dp[i + 1] = min(dp[i + 1], dp[i] + 1);
        for (int j = 1;; j++) // 枚举蓄力时间
        {
            int x = i + j * j; // 蓄力跳跃的落点
            if (x > n)
                break;
            dp[x] = min(dp[x], dp[i] + j + 1);
        }
    }
    cout << dp[n];
    return 0;
}