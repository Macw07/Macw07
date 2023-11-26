#include <iostream>
#include <algorithm>
using namespace std;

int n, m, sum;
int arr[25];
bool vis[25], flag;

// now：当前的长度；len：变长；t：拼好的根数
void dfs(int now, int len, int t){
    if (flag) return;
    if (now == len) {
        dfs(0, len, t + 1);
        return ;
    }
    if (t == 4) {
        flag = 1;
        return ;
    }
    for (int i=0; i<m; i++){
        if (now + arr[i] > len || vis[i]) continue;
        vis[i] = 1;
        dfs(now + arr[i], len, t);
        vis[i] = 0;
    }
    return ;
}

int main(){
    cin >> n;
    for (int i=1; i<=n; i++){
        cin >> m;
        sum = 0;
        for (int j=0; j<m; j++) {
            cin >> arr[j];
            sum += arr[j];
        }
        if (sum % 4) {
            cout << "no" << endl;
            continue;
        }
        flag = 0;
        dfs(0, sum/4, 0);
        if (flag){
            cout << "yes" << endl;
        } else cout << "no" << endl;
    }
    return 0;
}