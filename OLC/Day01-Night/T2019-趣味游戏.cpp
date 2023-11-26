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

int main(){
    scanf("%lld %lld", &n, &c);
    for (int i=1; i<=n; i++) scanf("%lld", &arr[i]);
    sort(arr+1, arr+1+n);
    
    for (int i=1; i<=n; i++){
        // 在区间[i, n]中寻找B即可
        ll target = arr[i]-c;
        ll lb = search_lower(1, n, target);
        ll ub = search_upper(1, n, target);
        if (ub >= 1 && lb >= 1) {
            sum += ub - lb + 1;
            // cout << ub << " " << lb << endl;
        }
    }

    // cout << search_upper(1, n, 5) << endl;
    // cout << search_lower(1, n, 5) << endl;

    cout << sum << endl;
    return 0;
}