#include <iostream>
#include <algorithm>
using namespace std;

string dp[55000] = {};

string multiply(string a, string b){
    int arr[1000005] = {};
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    // 各位相乘
    for (int i=0; i<a.size(); i++){
        for (int j=0; j<b.size(); j++){
            arr[i+j] += (a[i]-'0')*(b[j]-'0');
        }
    }
    // for (int i=0; i<a.size()+b.size()-1; i++){
    //     cout << arr[i] << " ";
    // }
    // cout << endl;
    // 匀一匀
    for (int i=0; i<=a.size()+b.size(); i++){
        arr[i+1] += arr[i]/10;
        arr[i] %= 10;
    }
    // 输出
    bool flag = 1;
    string s;
    for (int i=a.size()+b.size()-1; i>=0; i--){
        if (flag && arr[i] == 0){
            continue;
        }
        flag = 0;
        s += arr[i]+'0';
    }
    return s;
}

string add(string a, string b){
    string s;
    int c=0;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    for (int i=0, j=0; i<a.size() || j<b.size() || c!=0; ){
        if (i<a.size()) c += a[i++]-'0';
        if (j<b.size()) c += b[j++]-'0';
        s += c%10+'0';
        c /= 10;
    }
    reverse(s.begin(), s.end());
    return s;
}

string convert(int n){
    string s;
    while(n){
        s += n%10+'0';
        n /= 10;
    }
    reverse(s.begin(), s.end());
    return s;
}

int main(){
    int n;
    cin >> n;
    dp[1] = "1";
    for (int i=2; i<=n; i++){
        dp[i] = multiply(dp[i-1], convert(i));
    }
    string ans="0";
    for (int i=1; i<=n; i++){
        ans = add(ans, dp[i]);
    }
    cout << ans;
    return 0;
}