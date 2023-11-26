#include <iostream>
using namespace std;

string a, b;
int la, lb;
int dp[2005][2005];

int main(){
    cin >> a >> b;
    la = a.size(), lb = b.size();
    for (int i=0; i<=la; i++){
        dp[i][0] = i;
    }
    for (int i=0; i<=lb; i++){
        dp[0][i] = i;
    }
    for (int i=1; i<=la; i++){
        for (int j=1; j<=lb; j++){
            if (a[i-1] == b[j-1]){
                dp[i][j] = dp[i-1][j-1];
            } else{
                dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + 1;
            }
        }
    }
    cout << dp[la][lb] << endl;
    return 0;
}