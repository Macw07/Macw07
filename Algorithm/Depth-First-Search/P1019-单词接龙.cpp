#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int n, ans;
string arr[25], begin_c;
int vis[25];

// 丢脸丢大了，vis的数值判断被我写成了t的数值判断。

int check(string pre, string end){
    for (int i=pre.size()-1; i>=0; i--){
        if (pre.size()-i > end.size()) continue;
        string s1 = pre.substr(i, pre.size());
        string s2 = end.substr(0, pre.size()-i);
        // cout << s1 << " " << s2 << endl;
        if (s1 == s2) {
            if (pre.size() == 1) return s1.size();
            if (s1.size() == pre.size()) return 0;
            if (s1.size() == end.size()) return 0;
            return s1.size();
        }
    }
    return 0;
}

void dfs(string current, int len){
    ans = max(ans, len);
    for (int i=1; i<=n; i++){
        if (vis[i] >= 2) continue;
        int t = check(current, arr[i]);
        if (t){
            vis[i] += 1;
            // cout << current + arr[i].substr(t, arr[i].size()) << endl;
            dfs(current + arr[i].substr(t, arr[i].size()), len+arr[i].size()-t);
            vis[i] -= 1;
        }
    }
    return ;
}

int main(){
    cin >> n;
    for (int i=1; i<=n; i++) cin >> arr[i];
    cin >> begin_c;
    dfs(begin_c, 1);
    cout << ans << endl;
    return 0;
}