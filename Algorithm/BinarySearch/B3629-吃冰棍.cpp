#include <iostream>
#include <algorithm>
using namespace std;

int n, ans;
int l = 1, r;

// 刚开始有mid个冰棍，测试是否可以兑换
bool check(int mid){
    int ans = mid;
    int stick = mid;
    while (stick >= 3){
        ans += stick / 3;
        stick = stick % 3 + stick / 3;
    }
    // cout << mid << " " << ans << endl;
    return ans >= n;
}

int main(){
    cin >> n; r = n;
    while(l <= r){
        int mid = (l+r) >> 1;
        if (check(mid)){
            r = mid - 1;
            ans = mid;
        } else l = mid + 1;
    }
    cout << ans << endl;
    return 0;
}