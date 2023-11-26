#include <iostream>
#include <algorithm>
using namespace std;

// 这个代码可以过疯狂的采药
// P1048 [NOIP2005 普及组] 采药

int n, w;
int c, v;
long long dp[10000005];

int main(){
    cin >> w >> n;
    for (int i=1; i<=n; i++){
        cin >> v >> c;
        for (int j=0; j<=w; j++){
            if (j >= v) dp[j] = max(dp[j], dp[j-v]+c);
        }
    }
    cout << dp[w] << endl;
    return 0;
}

/*
70 3
71 100
69 1
1 2

140
*/