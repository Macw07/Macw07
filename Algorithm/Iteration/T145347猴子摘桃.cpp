#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;

string arr[10005] = {};

string addition(string a, string b){
    string str;
    long long c=0;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    for (int i=0, j=0; i<a.size() || j<b.size() || c!=0;){
        if (i < a.size()){
            c += a[i]-'0';
            i++;
        }
        if (j < b.size()){
            c += b[j]-'0';
            j++;
        }
        str += c%10+'0';
        c /= 10;
    }
    reverse(str.begin(), str.end());
    return str;
}

int main(){
    int n;
    cin >> n;
    arr[0] = "2";
    for (int i=1; i<=n; i++){
        arr[i] = addition(arr[i-1], "1");
        arr[i] = addition(arr[i], arr[i]);
        // cout << arr[i] << endl;
    }
    cout << arr[n-1];
    // cout << pow(2, n+1)-2;
    return 0;
}

