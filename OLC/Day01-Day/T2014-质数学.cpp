#include <iostream>
using namespace std;

int n, ptr = 1;
long long ans = 0;
int arr[10005], vis[10005];

long long max(long long a, long long b){
    if (a > b) return a;
    return b;
}

void Euler_sieve(){
    vis[0] = vis[1] = 1;
    for (int i=2; i<=n; i++){
        if (!vis[i]){
            arr[ptr] = i;
            ptr += 1;
        }
        for (int j=1; j<ptr&&arr[j]*i<=n; j++){
            vis[arr[j] * i] = 1;
            if (i % arr[j] == 0) break;
        }
    }
    return ;
}

int main(){
    cin >> n;
    Euler_sieve();
    for (int i=2; i<=n/2; i++){
        if (!vis[i] && !vis[n-i]){
            ans = max(ans, i*(n-i));
        }
    }
    cout << ans << endl;
    return 0;
}