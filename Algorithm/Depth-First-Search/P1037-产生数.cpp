// #include <iostream>
// #include <algorithm>
// #include <unordered_map>
// using namespace std;

// long long k, ans;
// string str;
// char t1[25], t2[25];
// unordered_map<string, int> map;

// string replace(string str, char a, char b){
//     string s = str;
//     for (int i=0; i<str.length(); i++){
//         if (s[i] == a) s[i] = b;
//     }
//     return s;
// }

// void dfs(int index, string s){
//     if (index >= k) return ;
//     for (int i=0; i<=k; i++){
//         string ns = replace(s, t1[i], t2[i]);
//         if (map.count(ns)) continue;
//         map[ns] = 1;
//         ans += 1;
//         dfs(index + 1, ns);
//     }
//     return ;
// }

// int main(){
//     cin >> str >> k;
//     for (int i=0; i<k; i++) cin >> t1[i] >> t2[i];
//     dfs(0, str);
//     cout << ans << endl;
//     return 0;
// }

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int ans, k, a[30], b[30];
string num;
int sum[10005];
bool vis[30];

void dfs(int x){
    vis[x] = 1;  // 防止陷入循环
    ans += 1;
    for (int i=0; i<k; i++){
        if (a[i] == x && !vis[b[i]]) dfs(b[i]);
    }
    return ;
}

void HPM(int ans){
    // 高精度乘法 - 高精度乘低精度
    for (int i=1; i<=sum[0]; i++) sum[i] *= ans;
    for (int i=1; i<=sum[0]; i++) {
        if (sum[i] >= 10){
            sum[i+1] += sum[i] / 10;
            sum[i] %= 10;
            if (i == sum[0]) sum[0]++;
        }
    }
    return ;
}

int main(){
    cin >> num >> k;
    for (int i=0; i<k; i++) cin >> a[i] >> b[i];
    sum[0] = sum[1] = 1;  // sum[0]代表高精度的位数
    // 对每一位做处理
    for (int i=0; i<num.size(); i++){
        dfs(num[i]-'0');  // 求出每一位有多少种变换可能性。
        HPM(ans);  // 将答案存起来
        memset(vis, 0, sizeof vis);
        ans = 0;
    }

    bool flag = 1;
    for (int i=sum[0]; i>=1; i--) cout << sum[i];
    return 0;
}