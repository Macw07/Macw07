#include <iostream>
using namespace std;

int n, m, l, r, c;
int a[100005], diff[100005];

int main(){
    cin >> n >> m;
    for (int i=1; i<=n; i++){
        cin >> a[i];
    }
    while(m--){
        cin >> l >> r >> c;
        diff[l] += c;
        diff[r+1] -= c;
    }
    for (int i=1; i<=n; i++){
        diff[i] = diff[i] + diff[i-1];
        cout << diff[i]+a[i] << " ";
    }
    return 0;
}