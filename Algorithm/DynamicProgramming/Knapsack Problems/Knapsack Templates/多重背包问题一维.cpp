#include <iostream>
#include <algorithm>
using namespace std;

int v[105], c[105], num[105], n, w;
int dp[105];

int main(){
    cin >> n >> w;
    for (int i=1; i<=n; i++){
        cin >> c[i] >> v[i] >> num[i];
    }
    for (int i=1; i<=n; i++){
        for (int j=w; j>=0; j--){
            for (int k=0; k<=num[i]; k++){
                if (j >= k*v[i]){
                    dp[j] = max(dp[j], dp[j-k*v[i]]+k*c[i]);
                }
            }
        }
    }
    cout << dp[w] << endl;
    return 0;
}