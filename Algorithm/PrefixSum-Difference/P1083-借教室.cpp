#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

struct order{
    int d, s, t;
};

int n, m, ans;
int classroom[1000005];
order orders[1000005];
long long prefix[1000005];

bool check(int mid){
    memset(prefix, 0, sizeof prefix);
    for (int i=1; i<=mid; i++){
        order k = orders[i];
        prefix[k.s] += k.d;
        prefix[k.t+1] -= k.d;
    }
    for (int i=1; i<=n; i++){
        prefix[i] = prefix[i-1] + prefix[i];
        if (prefix[i] > classroom[i]){
            return false;
        }
    }
    return true;
}

int main(){
    cin >> n >> m;
    for (int i=1; i<=n; i++){
        cin >> classroom[i];
    }
    for (int i=1; i<=m; i++){
        int d, s, t;
        cin >> d >> s >> t;
        orders[i] = (order){d, s, t};
    }
    // 二分答案
    int l = 1, r = m;
    while(l <= r){
        int mid = (l+r) >> 1;
        if (check(mid)){
            l = mid + 1;
            ans = mid;
        } else r = mid - 1;
    }
    if (ans == m){
        cout << 0 << endl;
    } else{
        cout << -1 << endl;
        cout << ans + 1 << endl;
    }
    return 0;
}