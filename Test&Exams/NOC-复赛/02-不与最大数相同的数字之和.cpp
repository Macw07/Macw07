#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int max_ = -0x7f7f7f7f;
    int n, arr[105], ans = 0;
    cin >> n;
    for (int i=1; i<=n; i++){
        cin >> arr[i];
        max_ = max(max_, arr[i]);
    }
    for (int i=1; i<=n; i++){
        if (arr[i] == max_) continue;
        ans += arr[i];
    }
    cout << ans << endl;
    return 0;
}