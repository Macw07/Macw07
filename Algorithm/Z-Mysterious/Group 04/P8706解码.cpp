#include <iostream>
using namespace std;

int main(){
    string s, ans;
    getline(cin, s);
    int size = s.size();
    char pre = s[0];
    ans += pre;
    for (int i=1; i<size; i++){
        if (s[i] >= '0' && s[i] <= '9'){
            int end = s[i]-'0'-1;  // 因为已经加过一次了，所以不需要加
            for (int j=0; j<end; j++){
                ans += pre;
            } 
        } else{
            ans += s[i]; 
            pre = s[i];
        }
    }
    cout << ans << endl;
    return 0;
} 