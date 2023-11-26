#include <iostream>
using namespace std;

int n, q, t, a;
int vis[100000005], prime[100000005];
void linear_sieve(int k){
    vis[0] = vis[1] = 1;
    for (int i=2; i<=k; i++){
        if (!vis[i]){
            prime[++t] = i; 
        }
        for (int j=1; j<k&&prime[j]*i<=n; j++){
            vis[prime[j]*i] = 1;
            if (i % prime[j] == 0) break;
        }
    }
    return ;
}


int main(){
    cin >> n >> q;
    linear_sieve(n);
    while(q--){
        cin >> a;
        cout << prime[a] << endl;
    }
    return 0;
}