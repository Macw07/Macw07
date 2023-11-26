#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int objects[500], k;
int n, arr[200005];
int ans[200005];

int main(){
    cin >> n;
    n -= 1;
    // 经典01背包问题了。
    for (int i=2; i<=448; i++){
        objects[i] = i * i;
        if (objects[i] > n){
            k = i-1;
            break;
        }
    }
    memset(ans, 0x7f, sizeof ans);
    ans[0] = 0;
    ans[1] = 0;
    // 背包容量：n
    // 物品的价值：objects[i]
    for (int i=2; i<=k; i++){
        for (int j=0; j<=n; j++){
            if (j >= objects[i]){
                if (arr[j-objects[i]] + objects[i] >= arr[j]){
                    arr[j] = arr[j-objects[i]] + objects[i];
                    ans[j] = ans[j-objects[i]] + i + 1;
                }
                if (arr[j-objects[i]] + objects[i] == arr[j]){
                    ans[j] = min(ans[j], ans[j-objects[i]]) + i + 1;
                }
            }
        }
    }
    if (ans[n] == 0x7f7f7f7f) cout << n - arr[n] << endl;
    else cout << n - arr[n] + ans[n] << endl;

    // cout << ans[n] << " " << arr[n] << endl;
    return 0;
}