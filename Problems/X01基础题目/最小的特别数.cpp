#include <iostream>
#include <algorithm>
using namespace std;

int n;

int main(){
    cin >> n;
    while(n--){
        int t, k = 9;
        cin >> t;
        string ans;
        while(t > k){
            ans += k + '0';
            t -= k; k--;
            if (k == 0) break; 
        }
        ans += (t + '0');
        reverse(ans.begin(), ans.end());
        if (k) cout << ans << endl;
        else cout << -1 << endl;
    }
    return 0;
}