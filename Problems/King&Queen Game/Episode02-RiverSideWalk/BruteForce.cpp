#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int n, k, ans;
int arr[1000005];

int main(){
    // freopen("data/textcase010.in", "r", stdin);
    cin >> n >> k;
    for (int i=1; i<=n; i++) cin >> arr[i];
    for (int i=1; i<=n; i++){
        set<int> s;
        for (int j=i; j<=i+k-1 && j<=n; j++){
            s.insert(arr[j]);
        }
        int k = s.size();
        ans = max(ans, k);
    }
    cout << ans << endl;
    return 0;
}