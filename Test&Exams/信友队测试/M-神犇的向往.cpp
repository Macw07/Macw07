#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int score[105], timee[105];
int dp[100005];

int main(){
    cin >> n >> m;
    for (int i=1; i<=n; i++) cin >> score[i] >> timee[i];

    for (int i=1; i<=n; i++){
        for (int j=m; j>=0; j--){
            if (score[i] > j) continue;
            dp[j] = max(dp[j], dp[j-score[i]]+timee[i]);
        }
    }

    cout << dp[m] << endl;
    return 0;   
}