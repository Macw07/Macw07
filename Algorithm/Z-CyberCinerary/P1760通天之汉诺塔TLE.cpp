#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int n;
string total = "0";

string hpa(string a, string b){
    string ans;
    int c=0;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    int la=a.size(), lb=b.size();
    for(int i=0, j=0; i<la || j<lb || c!=0;){
        if (i<la) c += a[i++]-'0';
        if (j<lb) c += b[j++]-'0';
        ans += c%10+'0';
        c /= 10;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

// ? n=depth, char a, b, help refer to tower
void hannoi(long n, char a, char b, char help){
    total = hpa("1", total);
    // if only remains one tower
    if (n == 1){
        return;
    }
    hannoi(n-1, a, help, b);
    hannoi(n-1, help, b, a);
}

string dp[15010];

int main(){
    cin >> n;
    // hannoi(n, 'A', 'C', 'B');
    dp[0] = "0";
    dp[1] = "1";
    for (int i=2; i<=n; i++){
        dp[i] = hpa(dp[i-1], dp[i-1]);
        dp[i] = hpa(dp[i], "1");
    }
    cout << dp[n];
    return 0;
}