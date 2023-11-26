#include <iostream>
using namespace std;

typedef long long ll;

ll n, m, ans;
ll arr[100005];
ll prefix_sum[100005];

inline ll max(ll a, ll b){
    if (a > b) return a;
    return b;
}

inline bool check(ll i, ll mid){
    ll k = prefix_sum[mid] - prefix_sum[i-1];
    if (k <= m){
        ans = max(k, ans);
        return true;
    }
    return false;
}

int main(){
    scanf("%lld %lld", &n, &m);
    for (int i=1; i<=n; i++) {
        scanf("%lld", &arr[i]);
        prefix_sum[i] = prefix_sum[i-1] + arr[i];
    }
    // 从i点出发，找到第一个长度满足小于等于m的数字。
    for (int i=1; i<=n; i++){
        ll l = i, r = n;
        while(l <= r){
            ll mid = (l+r) >> 1;
            if (check(i, mid)) l = mid + 1;
            else r = mid - 1;
        }
    }
    cout << ans << endl;
    return 0;
}