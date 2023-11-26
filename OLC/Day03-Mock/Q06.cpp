#include <iostream>
#include <algorithm>
using namespace std;

int n, q, l, r, t;
int primes[1000005], prefix_sum[1000005];

void linear_sieve(int n){
    prefix_sum[0] = prefix_sum[1] = 1;
    for (int i=2; i<=n; i++){
        if (!prefix_sum[i]){
            primes[++t] = i;
        }
        for (int j=1; j<=t&&primes[j]*i<=n; j++){
            prefix_sum[primes[j]*i] = 1;
            if (i % primes[j] == 0) break;
        }
    }
    return ;
}

int main(){
    scanf("%d %d", &n, &q);
    linear_sieve(n);
    for (int i=1; i<=n; i++) prefix_sum[i] = prefix_sum[i] + prefix_sum[i-1];
    while(q--){
        int total = 0;
        scanf("%d %d", &l, &r);
        // 找到第一个小于等于l的数字以及第一个大于等于r的数字。
        int ans = (r-l+1) - (prefix_sum[r] - prefix_sum[l-1]);
        printf("%d\n", ans);
    }
    return 0;
}