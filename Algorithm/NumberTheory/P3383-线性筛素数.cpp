#include <iostream>
using namespace std;

int n, q, t = 1;
int arr[100000005];
int vis[100000005];

void prime_sieve(int range){
    vis[0] = vis[1] = 1;
    for (int i=2; i<=range; i++){
        if (!vis[i]){
            arr[t] = i;
            t += 1;
        }
        for(int j=1; j<t&&arr[j]*i<=range; j++){
            vis[arr[j]*i] = 1;
            if (i % arr[j] == 0){
                break;
            }
        }
    }
    return ;
}

int main(){
    scanf("%d %d", &n, &q);
    prime_sieve(n);
    while(q--){
        int k;
        scanf("%d", &k);
        cout << arr[k] << endl;
    }
    return 0;
}