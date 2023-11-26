#include <iostream>
using namespace std;

int arr[100005];

int main(){
    int n, target;
    cin >> n >> target;
    for (int i=0; i<n; i++){
        cin >> arr[i];
    }
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
    // cout << r << endl;
    if (r >= 0 && arr[r] == target){
        cout << r;
    } else{
        cout << -1;
    }
    return 0;
}