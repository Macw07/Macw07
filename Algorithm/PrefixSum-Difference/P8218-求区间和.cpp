#include <iostream>
using namespace std;

const int MAXN = 1e5+5;

int n, m;
int arr[MAXN];
int prefix[MAXN];

int main(){
    cin >> n;
    for (int i=1; i<=n; i++){
        cin >> arr[i];
        prefix[i] = prefix[i-1] + arr[i];
    }
    cin >> m;
    while(m--){
        int l, r;
        cin >> l >> r;
        int ans = prefix[r] - prefix[l-1];
        cout << ans << endl;
    }
    return 0;
}