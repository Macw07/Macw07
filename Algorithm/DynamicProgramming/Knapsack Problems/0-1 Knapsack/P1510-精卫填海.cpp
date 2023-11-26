#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

int v, n, c;
int k[10005], m[10005];
int dp[50005];

int main(){
    cin >> v >> n >> c;
    for (int i=1; i<=n; i++){
        cin >> k[i] >> m[i];
    }
    for (int i=1; i<=n; i++){
        for (int j=c; j>=0; j--){
            if (j >= m[i]){
                dp[j] = max(dp[j], dp[j-m[i]]+k[i]);
            }
        }
    }
    // 找到第一个合适的答案
    for(int i=0; i<=c; i++){
        // 如果可以填满就直接输出
        if (dp[i] >= v){
            cout << c-i << endl;
            return 0;
        }
    }
    cout << "Impossible" << endl;
    return 0;
}