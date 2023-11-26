#include <iostream>
using namespace std;

int arr[1000005];

int main(){
    int n, m;
    cin >> n >> m;
    for (int i=0; i<n; i++){
        cin >> arr[i];
    }
    // 多次二分查找
    while(m--){
        int target;
        cin >> target;
        // 二分查找
        int l=-1, r=n;
        while (l+1 != r){
            int m = (l+r)/2;
            if (arr[m] < target){
                l = m;
            } else{
                r = m;
            }
        }
        if (arr[r] == target){
            cout << r+1 << " ";
        } else{
            cout << -1 << " ";
        }
    }
    return 0;
}