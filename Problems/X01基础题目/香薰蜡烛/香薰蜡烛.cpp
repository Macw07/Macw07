#include <iostream>
using namespace std;

int main(){
    int l, r, ans = 0;
    int n, arr[1005];
    cin >> n;
    for (int i=1; i<=n; i++){
        cin >> arr[i];
    }
    cin >> l >> r;
    for (int i=l; i<=r; i++){
        if (arr[i] > ans){
            ans = arr[i];
        }
    }
    cout << ans << endl;
    return 0;
}