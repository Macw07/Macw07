#include <iostream>
using namespace std;

int arr[1000005];
int dp[1000005];

int main(){
    int n;
    cin >> n;
    for (int i=1; i<=n; i++){
        cin >> arr[i];
    }

    int ans = 0;
    for (int i=1; i<=n; i++){
        if (arr[i] > dp[ans]){
            ans += 1;
            dp[ans] = arr[i];
        } else{
            // 可以用二分优化
            // for (int j=1; j<=ans; j++){
            //     if (dp[j] > arr[i]){
            //         dp[j] = arr[i];
            //         break;
            //     }
            // }
            int l = 0, r = ans, cnt = 0;
            while(l <= r){
                int mid = (l+r)>>1;
                if (dp[mid] > arr[i]){
                    cnt = mid;
                    r = mid-1;
                } else{
                    l = mid+1;
                }
            }
            dp[cnt] = arr[i];
        }
    }
    cout << n-ans;
    return 0;
}