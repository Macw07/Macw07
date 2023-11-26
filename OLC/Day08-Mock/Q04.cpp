#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
ll cnt[105], arr[10005];
ll a, n, t;

ll split(ll n){
    ll ans = 0;
    for (ll i=1; i<=t; i++){
        if (!cnt[i]) continue;
        for (ll j=1; j<=t-i; j++){
            if (!cnt[j]) continue;
            for (ll k=1; k<=t-i-j; k++){
                if (!cnt[k]) continue;
                ll l = n - i - j- k;
                if (cnt[l] >= 1){
                    ll crt = 1;
                    crt = cnt[i]*cnt[j]*cnt[k]*cnt[l];
                    ans+=crt;
                }
            }
        }
    }
    return ans;
}

int main(){
    freopen("ticket.in", "r", stdin);
    freopen("ticket.out", "w", stdout);
    cin >> n >> t;
    for (ll i=0; i<n; i++){
        cin >> arr[i];
        cnt[arr[i]]++;
    }
    // 进行抽奖
    cout << split(t) << endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}