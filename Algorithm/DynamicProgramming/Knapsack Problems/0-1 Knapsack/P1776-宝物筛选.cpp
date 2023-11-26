#include <iostream>
#include <algorithm>
using namespace std;

int n, wk, pointer = 1;
int vi[10005], wi[10005]; 
int dp[500005];

int main(){
    cin >> n >> wk;
    for (int i=1; i<=n; i++){
        int c, w, ni;
        cin >> c >> w >> ni;
        // 二进制拆分
        for(int j=1; j<=ni; j++){
            vi[pointer] = j * c;
            wi[pointer] = j * w;
            pointer += 1;
            ni -= j;
        }
        if (ni){  // 如果有剩余
            vi[pointer] = ni * c;
            wi[pointer] = ni * w;
            pointer += 1;
        }
    }
    for (int i=1; i<pointer; i++){
        for (int j=wk; j>=0; j--){
            if (j >= wi[i]){
                dp[j] = max(dp[j], dp[j-wi[i]]+vi[i]);
            }
        }
    }
    cout << dp[wk] << endl;
    return 0;
}