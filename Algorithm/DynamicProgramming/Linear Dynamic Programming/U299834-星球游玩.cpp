#include <iostream>
using namespace std;

int dp[10005], n;
string arr[10005];
string dp_arr[10005];
string str, ans;
int ans_len;

bool cmp(string a, string b){
    int lena = a.size();
    int lenb = b.size();
    for (int i=0; i<max(lena, lenb); i++){
        if (i >= lena) return true;
        if (i >= lenb) return false;
        if (a[i] != b[i]) return a[i] < b[i];
    }
    return false;
}

int main(){
    cin >> str;
    int len = str.size();
    string tmp;
    for (int i=0; i<len; i++){
        if (str[i] >= 'A' && str[i] <= 'Z'){
            arr[n++] = tmp;
            tmp = str[i];
        } else  tmp += str[i];
    }
    arr[n] = tmp;
    for (int i=1; i<=n; i++) {
        dp_arr[i] = arr[i];
        dp[i] = 1;
    }
    
    for (int i=1; i<=n; i++){
        int temp = 0, index = 0;
        for (int j=1; j<i; j++){
            if (cmp(arr[j], arr[i])){
                // 找到前面可以拼接的最大值。
                if (dp[j] > temp){
                    temp = dp[j];
                    index = j;
                }
                if (dp[j] == temp && cmp(arr[j], arr[index])){
                    temp = dp[j];
                    index = j;
                }
            }
        }
        if (temp != 0){
            dp_arr[i] = dp_arr[index] + dp_arr[i];
            dp[i] = temp + 1;
            if (dp[i] > ans_len){
                ans_len = dp[i];
                ans = dp_arr[i];
            }
            if (ans_len && dp[i] == ans_len){
                if (cmp(dp_arr[i], ans)){
                    ans = dp_arr[i];
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}