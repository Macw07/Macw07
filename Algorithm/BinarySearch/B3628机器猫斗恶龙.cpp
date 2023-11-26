#include <iostream>
#include <algorithm>
using namespace std;

int arr[100005];
int n;
int l, r;

// 游戏check:这点血是否可以通关游戏
bool check(int m){
    for (int i=0; i<n; i++){
        m += arr[i];
        if (m <= 0){
            // cout << m << endl;
            return false;
        }
    }
    return true;
}

int main(){
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> arr[i];
    }
    // 二分查找
    l = -1, r=100000;
    int ans=100000;
    while (l+1 != r){
        int m = (l+r)/2;
        // cout << m << endl;
        if (check(m)){
            // cout << r << endl;
            r = m;
            ans = min(ans, r);
        } else{
            l = m;
        }
    }
    cout << ans;
    return 0;
}