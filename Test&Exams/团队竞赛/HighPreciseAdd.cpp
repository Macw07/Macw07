#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

string add(string a, string b){
    string ans = ""; 
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    int c = 0, lenA = a.size(), lenB = b.size();
    for (int i=0, j=0; i<lenA||j<lenB||c; i++, j++){
        if (i < lenA) c += (a[i] - '0');
        if (j < lenB) c += (b[j] - '0');
        ans += (c % 10 + '0');
        c /= 10;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main(){
    string a, b;
    cin >> a >> b;
    cout << (add(a, b)) << endl;;
    return 0;
}