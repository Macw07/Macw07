#include <iostream>
#include <algorithm>
using namespace std;

int n, k, ans;
int arr[100005];
int dp[100005];  

/*
最长上升子序列。
我是真的吐了，怎么这么狗的一道题。
又要用二分，又要用动态规划。
*/

bool check(int mid){
    ans = 1;
    for (int i=1; i<=n; i++){
        dp[i] = 1;
        for (int j=1; j<i; j++){
            if (arr[j] + mid <= arr[i]){
                dp[i] = max(dp[i], dp[j] + 1);
                ans = max(dp[i], ans);
                if (ans >= k) return 1;
            }
        }
    }
    return ans >= k; 
}

int main(){
    cin >> n >> k;
    for (int i=1; i<=n; i++) cin >> arr[i];
    
    int l = 0, r = 674657743, result = 0;
    while(l <= r){
        int mid = (l + r) >> 1;
        if (check(mid)){
            result = mid;
            l = mid + 1;
        } else r = mid - 1;
    }
    cout << result << endl;
    return 0;
}