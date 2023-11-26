#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

ll n, c, sum;
ll arr[200005];

ll search_lower(int l, int r, int k){
    ll ans = -1;
    while(l <= r){
        ll mid = (l+r) >> 1;
        if (arr[mid] < k) l = mid + 1;
        else if (arr[mid] > k) r = mid - 1;
        else if (arr[mid] == k){
            ans = mid;
            r = mid - 1;
        }
    }
    return ans;
}   

ll search_upper(int l, int r, int k){
    ll ans = -1;
    while(l <= r){
        ll mid = (l+r) >> 1;
        if (arr[mid] < k) l = mid + 1;
        else if (arr[mid] > k) r = mid - 1;
        else if (arr[mid] == k){
            ans = mid;
            l = mid + 1;
        }
    }
    return ans;
} 

ll search_higher_bound(int l, int r, int k){
    ll ans = -1;
    while(l <= r){
        ll mid = (l+r) >> 1;
        if (arr[mid] > k) {
            r = mid - 1;
            ans = mid;
        }
        else l = mid + 1;
    }
    return ans;
} 

int main(){
    scanf("%lld", &n);
    for (int i=1; i<=n; i++) scanf("%lld", &arr[i]);
    sort(arr+1, arr+1+n);
    scanf("%lld", &c);
    while(c--){
        ll target;
        scanf("%lld", &target);
        ll lb = search_lower(1, n, target);
        ll ub = search_upper(1, n, target);
        ll hb = search_higher_bound(1, n, target);
        if (arr[lb] == arr[ub] && arr[lb] == target) {
            cout << lb << " " << ub << " ";
        } else cout << "-1 -1 ";
        if (arr[hb] > target) cout << hb << endl;
        else cout << -1 << endl;
    }
    
    return 0;
}