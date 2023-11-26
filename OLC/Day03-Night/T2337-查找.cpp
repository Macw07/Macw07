#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

/*
Quote: A-B数对：将 A-B=C => A-C=B
因此，我们只需要去寻找B的数量就可以了。
至于如何寻找B的数量，我们可以通过多次二分查找来得到结果。
为了满足二分查找的单调性，我们需要给数组排序。
*/

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
    scanf("%lld", &n);
    for (int i=1; i<=n; i++) scanf("%lld", &arr[i]);
    sort(arr+1, arr+1+n);
    scanf("%lld", &c);
    while(c--){
        ll target;
        scanf("%lld", &target);
        ll lb = search_lower(1, n, target);
        ll ub = search_upper(1, n, target);
        if (arr[lb] == arr[ub] && arr[lb] == target) cout << ub-lb+1 << endl;
        else cout << 0 << endl;
    }
    
    return 0;
}