#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n;
    string ans;
    cin >> n;
    while(n){
        ans += n % 8 + '0';
        n /= 8;
    }
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
    return 0;
}