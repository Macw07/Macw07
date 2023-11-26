#include <iostream>
using namespace std;

int main(){
    // freopen("testcase010.in", "r", stdin);
    // freopen("testcase010.out", "w", stdout);
    int t, n, ti, ans;
    int arr[10] = {};
    cin >> t;
    while(t--){
        arr[1] = arr[2] = arr[3] = arr[4] = arr[5] = 0;
        ans = 2147483647;
        cin >> n;
        for (int i=1; i<=n; i++){
            cin >> ti;
            arr[ti] += 1;
        }
        for (int i=1; i<=5; i++){
            if (arr[i] < ans){
                ans = arr[i];
            }
        }
        if (ans == 0){
            cout << "SO SAD" << endl;
        } else{
            cout << ans << endl;
        }
    }
    return 0;
}