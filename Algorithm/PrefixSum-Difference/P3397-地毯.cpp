#include <iostream>
#include <algorithm>
using namespace std;

// 二维差分模版题

int n, m;
int dp[1005][1005];

int main(){
    cin >> n >> m;
    while(m--){
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for (int i=x1; i<=x2; i++){
            dp[i][y1] += 1;
            dp[i][y2+1] -= 1;
        }
    }
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            dp[i][j] += dp[i][j-1];
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}