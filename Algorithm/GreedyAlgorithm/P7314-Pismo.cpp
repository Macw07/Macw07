#include <iostream>
#include <algorithm>
using namespace std;

// 这道题好像用贪心可以过。
// 为了让区间的最大值减最小值最小，就要让最大值最小，最小值最大。
// 并且由于当[l,r]的长度越长，最大值和最小值的差会越来越大，因此只需要考虑(r-l+1)<=2的情况即可。

int n, ans = 0x7f7f7f7f;
int arr[100005];

int main(){
    cin >> n;
    for (int i=1; i<=n; i++) cin >> arr[i];
    for (int i=1; i<=n-1; i++){
        ans = min(ans, max(arr[i], arr[i+1]) - min(arr[i], arr[i+1]));
    }
    cout << ans << endl;
    return 0;
}