#include <iostream>
#include <cstring>
using namespace std;

const int MAXN = 100;
int t, n, m, cnt;
string str[MAXN + 5];
int ans[MAXN + 5];
int vis[105];

// 对每一位进行检测。
// 如果所有字符串的某一列的数字都相等，且答案相等，则这一个数就可以忽略。
bool check(int k, char c){
    int a = -1;
    for (int i=1; i<=m; i++){
        if (vis[i]) continue;
        if (str[i][k] == c){
            if (a == ans[i]|| a == -1){
                a = ans[i];
            } else return false;
        }
    }
    return a != -1;
}

void mark(int k, char c){
    for (int i=1; i<=m; i++){
        if (vis[i]) continue;
        if (str[i][k] == c){
            vis[i] = 1;
            cnt += 1;
        }
    }
    return ;
}

int main(){
    cin >> t;
    while(t--){
        cin >> n >> m;
        memset(vis, 0, sizeof vis); cnt = 0;
        for (int i=1; i<=m; i++) cin >> str[i] >> ans[i];

        // 枚举每一位。
        for (int i=1; i<=m; i++){
            for (int j=0; j<n; j++){
                bool flag = check(j, '1');
                if (flag) mark(j, '1');
                flag = check(j, '0');
                if (flag) mark(j, '0');
            }
        }
        if (cnt == m) cout << "OK" << endl;
        else cout << "LIE" << endl;
    }
    return 0;
}