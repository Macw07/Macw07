#include <iostream>
using namespace std;

int m, n, groups=0;
int dp[1005];

struct merchandise{
    int weight;
    int value;
};

int nums[1005];
merchandise arr[1005][1005];

int main(){
    cin >> m >> n;
    for (int i=1; i<=n; i++){
        int a, b, c;
        cin >> a >> b >> c;
        groups = max(groups, c);
        arr[c][nums[c]++] = (merchandise){a, b};
    }
    // 分组背包
    for (int i=1; i<=groups; i++){
        for (int j=m; j>=0; j--){
            for (int k=0; k<=nums[i]; k++){
                if (j < arr[i][k].weight) continue;
                dp[j] = max(dp[j], dp[j-arr[i][k].weight]+arr[i][k].value);
            }
        }
    }
    cout << dp[m] << endl;
    return 0;
}