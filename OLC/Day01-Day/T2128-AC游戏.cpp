#include <iostream>
#include <algorithm>
using namespace std;

// 最小的两个质数的乘积
int n, q, t;
int vis[1000005], prime[1000005];
void linear_sieve(int k){
    for (int i=2; i*i<=n; i++){
        if (vis[i]) continue;
        for (int j=i*i; j<=n; j+=i){
            vis[j] = 1;
        }
    }
}


int main(){
    cin >> n;
    linear_sieve(1000000);
    while(n--){
        cin >> q;
        int sum = 1, k = 0;
        for (int i=2; i<q; i++){
            if (q % i == 0 && vis[i] == 0){
                sum *= i;
                k += 1;
            }
            if (k == 2) break;
        }
        if (k == 0) cout << 1 << endl << 0 << endl;
        else if (k == 1 || sum == q) cout << 2 << endl;
        else cout << 1 << endl << sum << endl;
    }
    return 0;
}