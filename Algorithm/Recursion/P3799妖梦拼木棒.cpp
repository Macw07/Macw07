#include <iostream>
#include <algorithm>
using namespace std;

/*
整体思路：这道题是一道枚举的题目，本质上只需要枚举出所有的可能进行判断是否可以组成一个正三角形即可。
因为是4根木棍来组合一个三角形，所以四根木棍a, b, c, d必须满足以下条件： a == b && c + d == a（a, b, c, d的值并不固定)。
可能性：如果同一个长度（x）的木棍数量 > 2，枚举其他所有的木棍是否可以拼成x。
*/

int n, ma=0;  // ma和mn是负责控制枚举的范围的
int visited[100005];
int ans = 0, mod = 1e9+7;

int C2(int k){
    return ((k*k-k)/2)%mod;
}

int main(){
    cin >> n;
    for (int i=0; i<n; i++){
        int t;
        cin >> t;
        visited[t]++;
        ma = max(t, ma);
    }
    // 开始进行枚举
    for (int i=1;i<=ma;i++){
		for (int j=i;j<=ma;j++){
			if (i==j){
                ans=(ans+(C2(visited[i])*C2(visited[i+j])))%mod;
            } else ans=(ans+((visited[i]*visited[j])%mod*C2(visited[i+j]))%mod)%mod;
		}
	}
    cout << ans << endl;
    return 0;
}
