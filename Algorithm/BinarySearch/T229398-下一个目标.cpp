#include <iostream>
using namespace std;

int n, l, r, ans;
int arr[1000005], target;

int main(){
    cin >> n;
    for (int i=0; i<n; i++) cin >> arr[i];
    cin >> target;
    l = 0, r = n-1;
    while(l <= r){
        int mid = (l+r) >> 1;
        if (arr[mid] > target){
            ans = mid;
            r = mid - 1;
        } else l = mid + 1;
    }
    cout << ans << endl;
    return 0;
}