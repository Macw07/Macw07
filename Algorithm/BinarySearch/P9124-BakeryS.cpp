#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
ll T, n, c, m;
ll ans;
struct friends{
    ll a;
    ll b;
    ll c;
} arr[105];

ll max(ll a, ll b){
    if (a > b) return a;
    return b;
}

ll min(ll a, ll b){
    if (a < b) return a;
    return b;
}

bool check(int mid){
    
    ll Max = min(c-1, mid);
    ll Min = max(0, mid-m+1);
    for (int i=1; i<=n; i++){
        ll t = arr[i].b - arr[i].a;
        ll k = arr[i].c - arr[i].a * c - arr[i].b * m + arr[i].b * mid;
        if (t == 0 && k < 0) return false;
        if (t > 0) Max = min(Max, (ll)floor(1.0*k/t));
        if (t < 0) Min = max(Min, (ll)ceil(1.0*k/t));
    }
    return Max >= Min;
}

int main(){
    cin >> T;
    while(T--){
        cin >> n >> c >> m;
        for (ll i=1; i<=n; i++){
            cin >> arr[i].a >> arr[i].b >> arr[i].c;
        }
        ll L=0, R = c + m, ans;
        while(L <= R){
            ll mid = (L + R) >> 1;
            if (check(mid)){
                R = mid - 1;
                ans = mid;
            } else{
                L = mid + 1;
            }
        }
        cout << ans << endl;
    }
    return 0;
}