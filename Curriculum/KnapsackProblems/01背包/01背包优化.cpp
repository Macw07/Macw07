#include <iostream>
#include <algorithm>
using namespace std;

int n, m;  // n表示n件物品，m表示背包的容量
int volume[105], value[105];
int dp[1005];

int main(){
    cin >> m >> n;
    for (int i=1; i<=n; i++){
        cin >> volume[i] >> value[i];
    }
    for (int i=1; i<=n; i++){  // 表示当前的物品
        for (int j=m; j>=volume[i]; j--){  // 表示当前的容量
            dp[j] = max(dp[j], dp[j-volume[i]]+value[i]);
        }
    }
    cout << dp[m] << endl;
    return 0;
}