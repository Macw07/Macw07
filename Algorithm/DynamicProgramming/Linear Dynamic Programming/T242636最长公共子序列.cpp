#include <iostream>
#include <algorithm>
using namespace std;

int dp[105][105];

int main(){
    string a, b;
    cin >> a >> b;
    int la = a.size(), lb = b.size();

    for (int i=1; i<=la; i++){
        for (int j=1; j<=lb; j++){
            // cout << a[i-1] << " " << b[j-1] << endl;
            if (a[i-1] == b[j-1]) dp[i][j] = dp[i-1][j-1]+1;
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    // for (int i=1; i<=la; i++){
    //     for (int j=1; j<=lb; j++){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    cout << dp[la][lb] << endl;
}