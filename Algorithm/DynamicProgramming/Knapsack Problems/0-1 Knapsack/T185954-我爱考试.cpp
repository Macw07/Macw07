#include <iostream>
#include <algorithm>
using namespace std;

int n;
int p[500], part[500], f[500], full[500];
int dp[5005];

int main(){
    cin >> n;
    for (int i=1; i<=n; i++){
        cin >> p[i];
    }
    for (int i=1; i<=n; i++){
        cin >> part[i];
    }
    for (int i=1; i<=n; i++){
        cin >> f[i];
    }
    for (int i=1; i<=n; i++){
        cin >> full[i];
    }
    for (int i=1; i<=n; i++){
        for (int j=120; j>=0; j--){
            int p1=0, p2=0;
            if (j >= p[i]){
                p1 = max(dp[j], dp[j-p[i]]+part[i]);
            }
            if (j >= f[i]){
                p2 = max(dp[j], dp[j-f[i]]+full[i]);
            }
            dp[j] = max(p1, p2);
        }
    }
    cout << dp[120] << endl;
    return 0;
}