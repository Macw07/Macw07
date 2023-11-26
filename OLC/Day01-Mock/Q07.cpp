#include <iostream>
using namespace std;

int n, q, l, r, t;
int primes[1000005], vis[1000005];

void linear_sieve(int n){
    vis[0] = vis[1] = 1;
    for (int i=1; i<=n; i++){
        if (!vis[i]){
            primes[++t] = i;
        }
        for (int j=1; j<=t&&primes[j]*i<=n; j++){
            vis[primes[j]*i] = 1;
            if (i % primes[j] == 0) break;
        }
    }
    return ;
}

int main(){
    scanf("%d %d", &n, &q);
    linear_sieve(n);
    while(q--){
        int total = 0;
        scanf("%d %d", &l, &r);
        for (int i=l; i<=r; i++){
            if (!vis[i]) total += 1;
        }
        printf("%d\n", total);
    }
    return 0;
}