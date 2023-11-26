#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

queue<int> que;
int max_k;
int vis[10005];
int primes[10005], p = 1;

void prime_sieve(int k){
    vis[0] = vis[1] = 1;
    for (int i=3; i<=k; i++){
        for (int j=2; j*j<=i; j++){
            if (i % j == 0){
                vis[i] = 1;
                break;
            }
        }
    }
    return ;
}

int main(){
    int k;
    while(cin >> k && k != 0){
        max_k = max(max_k, k);
        que.push(k);
    }
    prime_sieve(max_k);
    // for (int i=1; i<=p; i++) cout << primes[i] << " ";
    while(!que.empty()){
        int t = que.front();
        que.pop();
        int total = 0;
        for (int i=2; i<t/2; i++){
            if (vis[i] == 0 && vis[t-i] == 0){
                // cout << i << " " << t-i << endl;
                total += 1;
            }
        }
        cout << total << endl;
    }
    return 0;
}