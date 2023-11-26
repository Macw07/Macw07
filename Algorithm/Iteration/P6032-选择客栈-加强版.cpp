#include <iostream>
#include <cstring>
using namespace std;

long long n, k, p, t;
long long color[2000005], price;
long long num[10005], ans;  // 表示第i个颜色在之前出现了几次。

int main(){
    scanf("%lld %lld %lld", &n, &k , &p);
    for (long long i=1; i<=n; i++) {
        scanf("%lld %lld", &color[i], &price);
        if (price <= p){
            for (long long j=i; j>t; j--){
                num[color[j]] += 1;
            }
            t = i, ans += num[color[i]]-1;
        } else{
            ans += num[color[i]];
        }
    }
    cout << ans << endl;
    return 0;
}
