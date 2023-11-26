#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

/*
将 A-B=C => A-C=B
因此，我们只需要去寻找B的数量就可以了。
至于如何寻找B的数量，我们可以通过多次二分查找来得到结果。
为了满足二分查找的单调性，我们需要给数组排序。
*/

ll n, c, sum;
ll arr[200005];

ll search_(int l, int r, int k){
    ll ans = -5;
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

int main(){
    scanf("%lld %lld", &n, &c);
    for (int i=1; i<=n; i++) scanf("%lld", &arr[i]);
    sort(arr+1, arr+1+n);
    
    for (int i=1; i<=n; i++){
        // 在区间[i, n]中寻找B即可
        ll target = arr[i]-c, l = 1;
        while (true){
            l = search_(l, n, target) + 1;
            if (l <= 0) break;
            sum += 1;
            if (arr[l] > target) break;
        }
    }

    cout << sum << endl;
    return 0;
}