#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int convert(string str){
    int ans = 0, len = str.size();
    for (int i=0; i<len; i++){
        ans = ans * 10 + (str[i]-'0');
    }
    // cout << ans << endl;
    return ans;
}

int main(){
    string str, sstr;
    cin >> str;
    sstr = str.substr(0, 2);
    int ans = convert(str) - convert(sstr);
    cout << ans << endl;
    return 0;
}