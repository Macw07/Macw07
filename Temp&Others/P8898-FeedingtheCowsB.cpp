#include <iostream>
#include <cstring>
using namespace std;

const int MAXN = 1e5 + 5;
int t, n, k, cnt;
char arr[MAXN];
char ans[MAXN];
int vis[MAXN];

void mark(int pos, char type){
    if (ans[pos] != '.') {
        mark(pos + 1, type);
        return ;
    }
    ans[pos] = type;
    for (int i=max(1, pos-k); i<=min(n, pos+k); i++){
        if (arr[i] == type){
            vis[i] = 1;
        }
    }
    return ;
}

int main(){
    cin >> t;
    while(t--){
        cin >> n >> k;
        cnt = 0;
        memset(vis, 0, sizeof vis);
        for (int i=1; i<=n; i++) {
            cin >> arr[i];
            ans[i] = '.';
        }
        for (int i=1; i<=n; i++){
            if (vis[i] == 0){
                cnt += 1;
                if (i + k >= n) mark(i, arr[i]);
                else mark(i+k, arr[i]);
            }
        }
        cout << cnt << endl;
        for (int i=1; i<=n; i++) cout << ans[i];
        cout << endl;
    }
    return 0;
}