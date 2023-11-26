#include <iostream>
#include <algorithm>
using namespace std;

int ans = 0;
int n, m, k;
int dp[1005][1005];

int main(){
    cin >> n >> m >> k;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            cin >> dp[i][j];
            dp[i][j] += dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
        }
    }
    while(k--){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1 -= 1, y1 -= 1;
        int area = dp[x2][y2] - dp[x1][y2] - dp[x2][y1] + dp[x1][y1];
        cout << area << endl;
    }
    return 0;
}