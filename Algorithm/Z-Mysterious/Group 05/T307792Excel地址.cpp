#include <iostream>
#include <algorithm>
using namespace std;

// so sad 以为只要25个字母
// 这道题很无语诶，unsigned long long 过不了 int64过得了

int main(){
    int64_t n;
    string ans = "";
    cin >> n;
    while(n){
        if (n % 26 == 0) {ans += 'Z'; n/=26; n-=1;}
        else {ans += char((n % 26)+64); n /= 26;}
    }
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
    return 0;
}