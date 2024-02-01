#include <iostream>
#include <algorithm>
using namespace std;

int MOD = 20080707;
int n, m;
int arr[1005];

int main(){
    // freopen("Data/testcase20.in", "r", stdin);
    // freopen("Data/testcase20.out", "w", stdout);
    cin >> n >> m;
    for (int i=1; i<=n; i++){
        if (i <= m) arr[i] += 1;
        for (int j=max(1, i-m); j<i; j++){
            arr[i] += arr[j];
            arr[i] %= MOD;
        }
    }
    cout << arr[n] << endl;
    return 0;
}