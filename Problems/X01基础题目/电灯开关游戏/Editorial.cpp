#include <iostream>
using namespace std;

int n, m, cnt;
int arr[10005];

int main(){
    freopen("testcase010.in", "r", stdin);
    freopen("testcase010.out", "w", stdout);
    cin >> n >> m;
    for (int i=1; i<=n; i++) arr[i] ^= 1;
    while(m--){
        int k; cin >> k;
        arr[k] ^= 1;
        arr[k-1] ^= 1;
        arr[k+1] ^= 1; 
    }
    for (int i=1; i<=n; i++) cnt += arr[i];
    cout << cnt << endl;
    return 0;
}