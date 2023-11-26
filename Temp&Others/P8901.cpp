#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int t, n;
bool vis[5000005];
int ei, primes[348515];
int tmp[10] = {0, 1};
int ans[5000005] = {0, 1};

void linear_sieve(int range){
    vis[0] = vis[1] = 1;
    for (int i=2; i<=range; i++){
        if (vis[i] == 0){
            ei += 1;
            primes[ei] = i;
            if (i % 4 != 0){
                tmp[i%4] = i;
            }
        }
        for (int j=1; j<=ei && primes[j]*i <= range; j++){
            vis[i * primes[j]] = 1;
            if (i % primes[j] == 0) break;
        }
        if (i % 4 == 0){
            ans[i] = i / 4 + 1;
        } else {
            ans[i] = (i - tmp[i % 4])/4 + 1;
        }
    }
    return ;
}

int main(){
    // freopen("test.in", "r", stdin);
    linear_sieve(5000005);
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        int min1 = 1e9, min2 = 1e9;
        int mark1 = 0, mark2 = 0, k;
        for (int i=1; i<=n; i++){
            scanf("%d", &k);
            if (k % 4 == 0){
                if (min2 > ans[k]){
                    min2 = ans[k];
                    mark2 = i;
                }
            } else {
                if (min1 > ans[k]){
                    min1 = ans[k];
                    mark1 = i;
                }
            }
        }
        if (min1 < min2) cout << "Farmer John\n";
        else if (min1 > min2) cout << "Farmer Nhoj\n";
        else {
            if (mark1 < mark2) cout << "Farmer John\n";
            else cout << "Farmer Nhoj\n";
        }
    }
    return 0;
}