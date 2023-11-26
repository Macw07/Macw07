#include <iostream>
#include <algorithm>
using namespace std;

int arr[10005];

int main(){
    int n, k;
    cin >> n >> k;
    for (int i=0; i<n; i++) cin >> arr[i];
    sort(arr, arr+n);
    int cnt = 1, pre = arr[0];
    bool check = 0;
    for (int i=1; i<n; i++){
        if (arr[i] == pre) continue;
        pre = arr[i];
        if (cnt == k){
            check = 1;
            cout << arr[i-1];
            break;
        }
        cnt++;
    }
    if (!check){
        cout << "NO RESULT";
    }
    return 0;
}