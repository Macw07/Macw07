#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr[1005];
int dp[1005];

int main(){
    cin >> n;
    for (int i=1; i<=n; i++){
        cin >> arr[i];
    }
    // 思路：从第一个格子开始跳跃，如果把所有可以跳到的格子设定为1，看看能否跳到最后一个格子
    dp[1] = 1;
    for (int i=2; i<=n; i++){
        for (int j=1; j<i; j++){
            if (arr[j]+j>=i && dp[j]){
                dp[i] = 1;
                break;
            }
        }
    }
    if (dp[n]) cout << "true" << endl;
    else cout << "false" << endl;
    return 0;
}