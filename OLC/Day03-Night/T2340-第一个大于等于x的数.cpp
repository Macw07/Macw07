#include <algorithm>
#include <iostream>
using namespace std;

int n, arr[105], k;

int main(){
    scanf("%d", &n);
    for (int i=1; i<=n; i++) scanf("%d", &arr[i]);
    scanf("%d", &k);
    int l = 1, r = n, ans = -0x7f7f7f7f;
    while(l <= r){
        int mid = (l+r) >> 1;
        if (arr[mid] >= k) {
            ans = mid;
            r = mid - 1;
        } else l = mid + 1;
    }
    if (ans) cout << ans  << endl;
    else cout << -1 << endl;
    return 0;
}