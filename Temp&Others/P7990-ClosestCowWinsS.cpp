#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

typedef long long ll;
const ll MAXN = 2e5;
ll n, m, C, ans;
struct field{
    ll x;
    ll y;
    bool friend operator < (field a, field b){
        return a.x < b.x;
    }
} d[MAXN + 5];
ll x[MAXN + 5];
ll s[MAXN + 5];
priority_queue<field> q;

signed main(){
    cin >> n >> m >> C;
    field tmp;
    for (ll i=1; i<=n; i++){
        cin >> tmp.x >> tmp.y;
        d[i] = tmp;
    }
    for (ll i=1; i<=m; i++) cin >> x[i];
    sort(d+1, d+n+1);
    sort(x+1, x+m+1);
    for (ll i=1; i<=n; i++) s[i] = s[i-1] + d[i].y;
    x[0] = -2e9; x[m+1] = 2e9;
    for (ll i=0; i<=m; i++){
        ll l = upper_bound(d+1, d+n+1, (field){x[i], 0}) - d;
        ll r = lower_bound(d+1, d+n+1, (field){x[i+1], 0}) - d;
        if (l > --r) continue;
        ll c = x[i+1] - x[i]; ll v = 0;
        ll j, k;
        for (j = k = l; j<r; j++){
            for (; k<=r; k++){
                if ((d[k].x - d[j].x) << 1 >= c){
                    break;
                }
            }
            if (s[--k]-s[j-1]>v){
                v = s[k] - s[j-1];
            }
            q.push((field){v, s[r]-s[l-1]-v});
        }
    }
    while(C--){
        field t = q.top();
        q.pop();
        ans += t.x;
        q.push((field){t.y, 0});
    }
    cout << ans << endl;
    return 0;
}

/*
6 5 6
0 4
4 6
8 10
10 8
12 12
13 14
2
3
5
7
11
*/