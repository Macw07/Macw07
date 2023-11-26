#include <iostream>
#include <algorithm>
using namespace std;

int n, w;
int c, v;
int dp[1005];

int main(){
    cin >> n >> w;
    for (int i=1; i<=n; i++){
        cin >> c >> v;
        for (int j=w; j>=v; j--){
            dp[j] = max(dp[j], dp[j-v]+c);
        }
    }
    cout << dp[w] << endl;
    return 0;
}