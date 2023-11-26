#include <iostream>
#include <algorithm>
using namespace std;

int n, m, total;
int l=1, r=1;
int a[20005], b[20005];

int main(){
    cin >> n >> m;
    for (int i=1; i<=n; i++) cin >> a[i];
    for (int j=1; j<=m; j++) cin >> b[j];
    sort(a+1, a+n+1); sort(b+1, b+m+1);
    while(l <= n && r <= m){
        if (a[l] > b[r]) r++;
        else{
            total += b[r];
            l++; r++;
        }
    }
    if (l<=n && r>m) cout << "you died!" << endl;
    else cout << total << endl;
    return 0;
}