#include <iostream>
using namespace std;

int n, m, arr[10005];

int main(){
    // freopen("testcase001.in", "r", stdin);
    // freopen("testcase001.out", "w", stdout);
    cin >> n >> m;
    for (int i=1; i<=n; i++) arr[i] = i;

    // 找到第x位病人。
    while(m--){
        int k, cnt = 0;
        cin >> k;
        for (int i=1; i<=n; i++){
            if (arr[i] == -1) continue;
            cnt++;
            if (cnt == k){
                arr[i] = -1;
                break;
            }
        }
    }

    int q, cnt = 0;
    cin >> q;
    for (int i=1; i<=n; i++){
        if (arr[i] == -1) continue;
        cnt++;
        if (cnt == q){
            cout << arr[i] << endl;
            break;
        }
    }
    return 0;
}