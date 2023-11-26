#include <iostream>
#include <algorithm>
using namespace std;

int n, ans, len, tlen, head=0;
int arr[1000005];
int cnt[1000005];

int main(){
    scanf("%d", &n);
    // tlen = n-1;
    for (int i=1; i<=n; i++) {
        scanf("%d", &arr[i]);
        cnt[arr[i]] += 1;
        if (cnt[arr[i]] == 1){
            len += 1;
        }
    }
    sort(arr, arr+n);
    cout << n/2 << " " << arr[n/2] << " " << arr[n/2+1] << endl;
    return 0;
}