#include <iostream>
using namespace std;

int n, q, t, mode, x, a, b;
long long total, arr[100005];

int main(){
    scanf("%d %d", &n, &q);
    for (int i=1; i<=n; i++) {
        scanf("%lld", &arr[i]);
        total += arr[i];
        if (arr[i] % 2 == 1) a++;
        else b++;
    }
    while(q--){
        scanf("%d %d", &mode, &x);
        if (mode == 1) {
            total = (total + (a*x)) % 1000000007;
            if (x % 2 == 1) {
                b += a;
                a = 0;
            } 
        }
        else {
            total = (total + (b*x)) % 1000000007;
            if (x % 2 == 1){
                a += b;
                b = 0;
            }
        }
        printf("%lld\n", total);
    }
    return 0;
}