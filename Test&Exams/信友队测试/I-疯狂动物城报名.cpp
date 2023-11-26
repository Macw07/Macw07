#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int arr[100000];


int main(){
    cin >> n >> m;
    for (int i=1; i<=n; i++) cin >> arr[i];
    while(m--){
        int lb = 1, rb = n, ans = -1, k;
        cin >> k;

        while(lb <= rb){
            int mid = (lb+rb)>>1;
            if (arr[mid] < k){
                lb = mid + 1;
            } else if (arr[mid] > k){
                rb = mid - 1;
            } else {
                ans = mid;
                rb = mid - 1;
            }
        }

        if (ans == -1) {
            cout << -1 << " " << -1 << endl;
            continue;
        } 
        cout << ans << " ";

        lb = ans, rb = n, ans = -1;
        while(lb <= rb){
            int mid = (lb+rb)>>1;
            if (arr[mid] < k){
                lb = mid + 1;
            } else if (arr[mid] > k){
                rb = mid - 1;
            } else {
                ans = mid;
                lb = mid + 1;
            }
        }
        cout << ans << endl;
    }
    return 0;
}