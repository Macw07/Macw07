#include <iostream>
using namespace std;

int main(){
    int n, t, last, tmp = 0;
    int ans = 0, ans_altitude = 0;
    cin >> n;
    for (int i=1; i<=n; i++){
        cin >> t;
        if (i == 1) last = t;
        if (last == t) tmp += 1;
        else {
            tmp = 1;
            last = t;
        }
        if (tmp > ans){
            ans = tmp;
            ans_altitude = t;
            continue;
        }   
        if (tmp == ans && t < ans_altitude){
            ans_altitude = t;
        }
    }
    cout << "Length=" << ans << endl;
    cout << "Altitude=" << ans_altitude << endl;
    return 0;
}