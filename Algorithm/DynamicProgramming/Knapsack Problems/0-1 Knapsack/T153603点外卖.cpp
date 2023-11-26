#include <iostream>
#include <algorithm>
using namespace std;

int n, m, sum = 0;
int dp[1005];
int v[1005];

int main(){
    cin >> n >> m;
    for (int i=1; i<=n; i++){
        cin >> v[i];
    }
    for (int i=1; i<=n; i++){
        for (int j=1005; j>=v[i]; j--){
            dp[j] = max(dp[j], dp[j-v[i]]+v[i]);
        }
    }
    int i=m;
    while(dp[i] < m){i++;};
    cout << dp[i];
    return 0;
}