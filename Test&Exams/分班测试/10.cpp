#include <stdio.h>
#include <algorithm>

int n, t;
long long total;
int a[200005];
int diff[200005];

int main(){
    scanf("%d", &n);
    for (int i=1; i<=n; i++) scanf("%d", &a[i]);
    for (int i=1; i<=n; i++) {
        scanf("%d", &t);
        diff[i] = a[i] - t;
    }
    std::sort(diff+1, diff+1+n);
    // ai - bi + bi - bj > 0
    for (int i=1; i<=n; i++){
        int target = 0 - diff[i] + 1;
        int l = i+1, r = n, ans = n+1;
        while(l <= r){
            int mid = (l+r) >> 1;
            if (diff[mid] >= target){
                ans = mid;
                r = mid - 1;
            } else l = mid + 1;
        }
        total += n - ans + 1;
    }
    printf("%lld\n", total);
    return 0;
}
