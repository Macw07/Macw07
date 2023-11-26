#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int n;
int max_n = 0;
queue<int> que;
long long dp[10005];

int main(){
    cin >> n;
    while(n--){
        int t;
        cin >> t;
        max_n = max(max_n, t);
        que.push(t);
    }
    dp[1] = 2;
    dp[2] = 4;
    dp[3] = 8;
    for (int i=4; i<=max_n; i++){
        dp[i] = dp[i-1] + 2*(i-1);
    }

    while(!que.empty()){
        int t = que.front();
        que.pop();
        cout << dp[t] << endl;
    }
    return 0;
}