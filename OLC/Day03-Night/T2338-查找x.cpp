#include <algorithm>
#include <iostream>
using namespace std;

int n, arr[105], k;

int main(){
    scanf("%d", &n);
    for (int i=1; i<=n; i++) scanf("%d", &arr[i]);
    scanf("%d", &k);
    int l = 1, r = n;
    while(l <= r){
        int mid = (l+r) >> 1;
        if (arr[mid] == k){
            cout << mid << endl;
            return 0;
        } else if (arr[mid] < k) l = mid + 1;
        else r = mid - 1;
    }
    cout << -1 << endl;
    return 0;
}