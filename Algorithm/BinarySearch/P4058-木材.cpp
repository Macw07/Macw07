#include <iostream>
#include <algorithm>
using namespace std;

unsigned long long n, s, l, ans;
__int128 arr[200005], h[200005], a[200005];

bool check(__int128 mid){
    __int128 total = 0;
    for (int i=n; i>=1; i--){
        if (h[i] + a[i]*mid >= l) total += h[i] + a[i]*mid;
        if (total >= s) return true;
    }
    return false;
}

int main(){
    scanf("%lld %lld %lld", &n, &s, &l);
    for (int i=1; i<=n; i++) scanf("%d", &h[i]);
    for (int j=1; j<=n; j++) scanf("%d", &a[j]);

    if (check(0)) {cout << 0; return 0;}

    __int128 le = 0, ri = 1e18;
    while(le <= ri){
        __int128 mid = (le+ri) >> 1;
        if (check(mid)){
            ri = mid - 1;
            ans = mid;
        } else le = mid + 1;
    }
    cout << ans << endl;
    return 0;
}