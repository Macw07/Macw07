#include <iostream>
#include <algorithm>
using namespace std;

int dp[250][250];

int main(){
    string a, b;
    int ans = 0;
    cin >> a >> b;
    for (int i=0; i<a.size(); i++){
        for (int j=0; j<b.size(); j++){
            if (a[i] == b[j]) dp[i][j] = dp[i-1][j-1] + 1;
            ans = max(ans, dp[i][j]);
        }
    }
    while(dp[p1][p2]){
        
    }
    cout << ans << endl;
    return 0;
}