#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

int main()
{
    fastio;
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int ans = 2e9; // 数据范围 -1e9 ~ 1e9
    for (int i = 2; i <= n; i++)
        ans = min(ans, abs(a[i] - a[i - 1])); // 绝对值就是大的减小的
    cout << ans << endl;
    return 0;
}