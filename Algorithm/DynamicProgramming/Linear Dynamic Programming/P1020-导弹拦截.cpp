#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

// 最长下降子序列
int ans;
int dp[100005];
int arr[100005];
int main(){
    int t = 1;
    while(cin >> arr[t]){t++;}
    memset(dp, 0x7f, sizeof dp);
    for (int i=1; i<t; i++){
        if (arr[i] <= dp[ans]){
            ans += 1;
            dp[ans] = arr[i];
        } else{
            int l = 0, r = ans, cnt = 0;
            while(l <= r){
                int mid = (l+r) >> 1;
                if (dp[mid] < arr[i]){
                    r = mid - 1;
                    cnt = mid;
                } else l = mid + 1;
            }
            dp[cnt] = arr[i];
        }
    }
    cout << ans << endl;

    ans = 0;
    memset(dp, 0, sizeof dp);
    for (int i=1; i<t; i++){
        if (arr[i] > dp[ans]){
            ans += 1;
            dp[ans] = arr[i];
        } else{
            int l = 0, r = ans, cnt = 0;
            while(l <= r){
                int mid = (l+r) >> 1;
                if (dp[mid] >= arr[i]){
                    r = mid - 1;
                    cnt = mid;
                } else l = mid + 1;
            }
            dp[cnt] = arr[i];
        }
    }
    cout << ans << endl;
    return 0;
}