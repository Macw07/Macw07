#include <iostream>
using namespace std;

long long n, k;
long long ans;
long long arr[100005];

int main(){
    cin >> n >> k;
    for (int i=1; i<=n; i++) cin >> arr[i];
    // 是否一起买更划算。
    ans += k + 1;
    for (int i=2; i<=n; i++){
        ans += 1 + min(k, arr[i]-arr[i-1]-1);
    }
    cout << ans << endl;
    return 0;
}