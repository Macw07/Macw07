#include <iostream>
#include <algorithm>
using namespace std;

string add(string a, string b){
    string s;
    int c=0;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    for (int i=0, j=0; i<a.size() ||  j<b.size() || c!=0; ){
        if (i < a.size()) c += a[i++]-'0';
        if (j < b.size()) c += b[j++]-'0';
        s += c%10+'0';
        c /= 10;
    }
    reverse(s.begin(), s.end());
    return s;
}

string arr[5005] = {};

int main(){
    int n;
    cin >> n;
    arr[0] = "1";
    arr[1] = "1";
    arr[2] = "2";
    for (int i=3; i<=n; i++){
        arr[i] = add(arr[i-1], arr[i-2]);
    }
    cout << arr[n] << endl;
    return 0;
}