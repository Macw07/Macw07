#include <iostream>
#include <algorithm>
using namespace std;

int n, ans;
int arr[50005];
int vis[50005];

// 如果区间[l,r]是7的倍数，r+1为7的倍数，则区间[l,r+1]也是7的倍数。

int main(){
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> arr[i];
        arr[i] = (arr[i-1] + arr[i]) % 7;
        if (arr[i] == 0){
            ans = max(ans, i);
            continue;
        }
        if (vis[arr[i]] == 0){
            vis[arr[i]] = i;
        } else{
            int diff = i - vis[arr[i]];
            ans = max(ans, diff);
        }
    }
    cout << ans << endl;
    return 0;
}