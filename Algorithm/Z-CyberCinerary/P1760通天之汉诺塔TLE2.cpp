#include <iostream>
#include <algorithm>
using namespace std;

int n;

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

string hpm(string a, int b){
    string ans;
    int la=a.size();
    int tl=la+2;
    reverse(a.begin(), a.end());
    int temp[1000] = {};
    for (int i=0; i<la; i++){
        temp[i] += (a[i]-'0')*b;
        // cout << temp[i] << endl;
    }
    temp[0] += 1;
    for (int i=0; i<la; i++){
        temp[i+1] += temp[i]/10;
        temp[i] %= 10;
        // cout << temp[i];
    }
    // cout << endl;
    while(temp[tl-1] == 0){
        tl--;
    }
    for (int i=0; i<tl; i++){
        ans += temp[i]+'0';
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

string dp[15010];

int main(){
    cin >> n; 
    dp[0] = "0";
    dp[1] = "1";
    dp[2] = "3";
    for (int i=3; i<=n; i++){
        dp[i] = hpm(dp[i-1], 2);
    }
    cout << dp[n] << endl;
    return 0;
}