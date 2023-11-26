#include <iostream>
#include <algorithm>
using namespace std;

// 差分算法模板题
const int MAXN = 5e6+5;

int n, p, ans = 0x7f7f7f7f;
int arr[MAXN];
int diff[MAXN];
int prefix[MAXN];

int main(){
    cin >> n >> p;
    for (int i=1; i<=n; i++){
        cin >> arr[i];
        diff[i] = arr[i] - arr[i-1];
    }
    while(p--){
        int x, y, z;
        cin >> x >> y >> z;
        diff[x] += z;
        diff[y+1] -= z;
    }
    for (int i=1; i<=n; i++){
        prefix[i] = prefix[i-1] + diff[i];
        ans = min(ans, prefix[i]);
    }
    cout << ans << endl;
    return 0;
}