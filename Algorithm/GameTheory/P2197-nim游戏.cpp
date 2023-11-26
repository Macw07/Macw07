#include <iostream>
using namespace std;

int t, c, a, ans;

int main(){
    cin >> t;
    while(t--){
        cin >> c;
        ans = 0;
        while(c--){
            cin >> a;
            ans ^= a;
        }
        if (ans) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}