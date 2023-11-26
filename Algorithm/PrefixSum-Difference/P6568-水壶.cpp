#include <iostream>
using namespace std;

int n, k, ans;
int arr[1000005];
int prefix[1000005];

// 找一段区间为k的前缀和。

int main(){
    cin >> n >> k;
    for (int i=1; i<=n; i++){
        cin >> arr[i];
        prefix[i] = prefix[i-1] + arr[i];
    }
    for (int i=1; i<=n-k; i++){
        int gain = prefix[i+k]-prefix[i-1];
        ans = max(ans, gain);
    }
    cout << ans << endl;
    return 0;
}