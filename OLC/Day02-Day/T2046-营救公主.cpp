#include <iostream>
#include <cmath>
using namespace std;

int n, k;
long long ans;
long long prefix_sum[1000005];

// 找一个区间为k的前缀和，使这个前缀和最大。

int main(){
    cin >> n >> k;
    for (int i=1; i<n; i++){
        cin >> prefix_sum[i];
        prefix_sum[i] += prefix_sum[i-1];
    }
    if (k == 0){
        cout << prefix_sum[n-1] << endl;
        return 0;
    }
    for (int i=1; i<=n; i++){
        // 区间：[i, i+k];
        int range = min(i+k, n);
        long long tmp = prefix_sum[range-1] - prefix_sum[i-1];
        if (abs(tmp) > ans){
            ans = tmp;
        }
    }
    if (ans < 0) cout << prefix_sum[n-1] + ans << endl;
    else cout << prefix_sum[n-1] - ans << endl;
    return 0;
}