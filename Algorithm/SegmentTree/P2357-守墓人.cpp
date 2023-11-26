#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
const ll MAXN = 2e5 + 5;
ll n, f, t, l, r, k;
ll arr[MAXN];
ll BIT[MAXN];
ll S[MAXN];

inline ll lowbit(ll k){
    return k & (-k);
}

void add(ll x, ll a){
    ll t = x;
    while(x <= n){
        BIT[x] += a;
        S[x] += a * (t-1);
        x += lowbit(x);
    }
    return ;
}

ll query(ll x){
    ll total = 0, t = x;
    while(x){
        total += t * BIT[x] - S[x];
        x -= lowbit(x);
    }
    return total;
}

signed main(){
    scanf("%lld %lld", &n, &f);

    for (ll i=1; i<=n; i++) {
        scanf("%lld", &arr[i]);
        add(i, arr[i] - arr[i-1]);
    }

    while(f--){
        scanf("%lld", &t);
        if (t == 1){
            scanf("%lld %lld %lld", &l, &r, &k);
            add(l, k);
            add(r+1, -k);
        } 
        else if (t == 2){
            scanf("%lld", &k);
            add(1, k); 
            add(2, -k);
        } else if (t == 3){
            scanf("%lld", &k);
            add(1, -k);
            add(2, k);
        } else if (t == 4){
            scanf("%lld %lld", &l, &r);
            ll ans = query(r) - query(l-1);
            printf("%lld\n", ans);
        } else{
            printf("%lld\n", query(1));
        }
    }
    return 0;
}