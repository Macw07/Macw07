// #include <iostream>
// #include <algorithm>
// using namespace std;

// const int MOD = 1000000007;
// // 1 1 6 11 47
// // 1 1 6 11 43
// int n, dp[300][2];

// int main(){
//     /*
//     分类讨论：
//     1. 一个空位
//         对0取反 dp[i-1][0]

//     2. 两个空位
//         直接加一对括号() dp[i-2][1]
//         * 取反再取反!! dp[i-2][1]
        
//         一与一，一与零，一或一，一或零
//         for (int i=1; i<=k-2; i++){
//             int j = k - i;
//             dp[k][1] += dp[i][1] * dp[j][1];
//             dp[k][1] += dp[i][0] * dp[j][1];
//             dp[k][1] += dp[i][1] * dp[j][0];
//         }
//     */
//     cin >> n;

//     dp[1][1] = dp[1][0] = 1;
//     dp[2][1] = dp[2][0] = 1;
//     dp[3][1] = dp[3][0] = 6;
//     dp[4][1] = dp[4][0] = 11;

//     for (int i=5; i<=10; i++){
//         dp[i][1] += dp[i-1][0];
//         dp[i][1] += 2 * dp[i-2][1];

//         dp[i][0] += dp[i-1][1];
//         dp[i][0] += 2 * dp[i-2][0];

//         for (int j=2; j<=i-3; j++){
//             int k = i - j - 1;
//             dp[i][1] += dp[j][1] * dp[k][1];  // a&b
//             dp[i][1] += dp[j][1] * dp[k][0];  // a||b
//             dp[i][1] += dp[j][0] * dp[k][1];

//             dp[i][0] += dp[j][0] * dp[k][0];
//             dp[i][0] += dp[j][0] * dp[k][1];
//             dp[i][0] += dp[j][1] * dp[k][0];
//         }
//     }

//     cout << dp[n][1] << " " << dp[n][0] << endl;
//     return 0;
// }

#include <iostream>
#include <algorithm>
#include <cstring>
#define f first
#define s second
using namespace std;
using ll = long long;
using ii = pair<int, int>;
const int MX = 1e5+5, MOD=1e9+7;

ll DP[2][4][1000];

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int T;cin>>T;
	while(T--){
		memset(DP, 0, sizeof DP);
		int N; cin>>N;
		DP[0][0][1] = DP[1][0][1] = 1;
		for (int i = 1; i < N; ++i) {
			// (X)
			(DP[0][0][i+2] += DP[0][0][i]+DP[0][1][i]+DP[0][2][i]+DP[0][3][i]) %= MOD;
			(DP[1][0][i+2] += DP[1][0][i]+DP[1][1][i]+DP[1][2][i]+DP[1][3][i]) %= MOD;
			// !X
			(DP[0][1][i+1] += DP[1][0][i]+DP[1][1][i]) %= MOD;
			(DP[1][1][i+1] += DP[0][0][i]+DP[0][1][i]) %= MOD;

			// X&Y
			for (int a = 1; a <= i; ++a) {
			for (int j = 1; j <= i; ++j) {
			    if (a != i && j != i) continue;
				ll sum = (DP[1][0][a]+DP[1][1][a]+DP[1][2][a])%MOD*(DP[1][0][j]+DP[1][1][j])%MOD;
				(DP[1][2][a+j+1] += sum) %= MOD;
				(DP[0][2][a+j+1] += (DP[0][0][a]+DP[0][1][a]+DP[0][2][a]+DP[1][0][a]+DP[1][1][a]+DP[1][2][a])%MOD*(DP[0][0][j]+DP[0][1][j]+DP[1][0][j]+DP[1][1][j])%MOD-sum+MOD) %= MOD;
			}
			}
			// X|Y
			for (int a = 1; a<=i;++a){
			for (int j = 1; j<=i; ++j) {
				if (a != i && j != i) continue;
				ll sum = (DP[0][0][a]+DP[0][1][a]+DP[0][2][a]+DP[0][3][a])%MOD*(DP[0][0][j]+DP[0][1][j]+DP[0][2][j])%MOD;
				(DP[0][3][a+j+1] += sum) %= MOD;
				(DP[1][3][a+j+1] += (DP[0][0][a]+DP[0][1][a]+DP[0][2][a]+DP[0][3][a]+DP[1][0][a]+DP[1][1][a]+DP[1][2][a]+DP[1][3][a])%MOD*(DP[0][0][j]+DP[0][1][j]+DP[0][2][j]+DP[1][0][j]+DP[1][1][j]+DP[1][2][j])%MOD-sum+MOD) %= MOD;
			}
			}
		}
		/*for (int k = 1; k <= 5; ++k) {
		for (int i = 0; i < 2; ++i) {
			for (int j = 0; j < 4; ++j) {
				cout << DP[i][j][k] << ' ';						
			}
		}
		cout << '\n';
		}*/
		cout << (DP[1][0][N]+DP[1][1][N]+DP[1][2][N]+DP[1][3][N])%MOD << '\n';
	}
	
}
