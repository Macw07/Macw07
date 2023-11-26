#include <iostream>
#include <algorithm>
using namespace std;

int t, k, cc;
string x;

string add(string a, string b){
    string ans;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    int lena = a.size(), lenb = b.size();
    int c = 0;
    for (int i=0, j=0; i<a.size() || j<b.size() || c; ){
        if (i < a.size()) c += (a[i]-'0'), i++;
        if (j < b.size()) c += (b[j]-'0'), j++;
        ans += (c%10) + '0';
        c /= 10;
        if (c) cc += 1;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main(){
    scanf("%d", &t);
    // cout << add("15", "95");
    while(t--){
        cin >> x >> k;
        if (x == "0"){
            cout << -1 << endl;
            continue;
        }
        if (k + x.size() - 1 >= 10000){
            cout << -1 << endl;
            continue;
        }
        for (int i=1; i<=k; i++) cout << 9;
        for (int j=1; j<x.size(); j++) cout << 0;
        cout << endl;
    }
    return 0;
}