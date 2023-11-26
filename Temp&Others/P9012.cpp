#include <iostream>
#include <algorithm>
using namespace std;

int q;
string target = "MOO";
// MOM || MOO

int main(){
    cin >> q;
    while(q--){
        string str;
        cin >> str;
        int len = str.size();
        int ans = 0x7f7f7f7f;
        for (int i=1; i<len-1; i++){
            if (str[i] == 'O'){
                string tmp = "";
                tmp += str[i-1]; tmp += str[i]; tmp += str[i+1];
                int cnt = 0;
                for (int j=0; j<3; j++){
                    if (tmp[j] != target[j]) cnt += 1;
                }
                ans = min(ans, len - 3 + cnt);
            }
        }
        if (ans == 0x7f7f7f7f) cout << -1 << endl;
        else cout << ans << endl;
    }
    return 0;
}