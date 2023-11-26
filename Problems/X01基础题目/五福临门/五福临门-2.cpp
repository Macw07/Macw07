#include <iostream>
using namespace std;

int main(){
    // freopen("testcase010.in", "r", stdin);
    // freopen("testcase010.out", "w", stdout);
    int t;
    cin >> t;
    while(t--){
        bool flag = 1;
        int arr[10] = {}, n, t, ans = 0;
        cin >> n;
        for (int i=1; i<=n; i++){
            cin >> t;
            arr[t] += 1;
        }
        while(flag){
            for (int i=1; i<=5; i++){
                if (arr[i]) arr[i]--;
                else flag = 0;
            }
            if (!flag) break;
            ans += 1;
        }
        if (ans == 0){
            cout << "SO SAD" << endl;
        } else{
            cout << ans << endl;
        }
    }
    return 0;
}