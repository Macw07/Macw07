#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n, ans=0, k=0;
    int arr[105] = {};
    cin >> n;
    for (int i=0; i<n; i++){
        int t;
        cin >> t;
        if (t % 2) arr[k++] = t;
        ans += t;
    }
    if (k == 0){
        cout << 0 << endl;
        return 0;
    }
    if (k % 2 == 0) {
        sort(arr, arr+k);
        ans -= arr[0];
    }
    cout << ans;
    return 0;
}