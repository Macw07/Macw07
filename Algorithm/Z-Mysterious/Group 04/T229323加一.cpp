#include <iostream>
#include <algorithm>
using namespace std;

string add(string a, string b){
    string ans;
    int c = 0, la=a.size(), lb=b.size();
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    for (int i=0, j=0; i<la || j<lb || c!=0;){
        if (i<la) c += a[i++]-'0';
        if (j<lb) c += b[j++]-'0';
        ans += c%10 + '0';
        c /= 10;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
int main(){
    int n;
    cin >> n;
    string s;
    for (int i=0; i<n; i++){
        int t;
        cin >> t;
        s +=  t + '0';
    }
    cout << add(s, "1") << endl;
    return 0;
}