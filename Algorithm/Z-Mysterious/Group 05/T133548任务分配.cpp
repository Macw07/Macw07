#include <iostream>
#include <algorithm>
using namespace std;

int arr[1005] = {};

int main(){
    int n, total=0, t;
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> t;
        total += t;
        arr[i] = t;
    }
    sort(arr, arr+n);
    int temp=0, cnt=0;
    for (int i=n-1; i>=0; i--){
        temp += arr[i];
        cnt++;
        if (temp > total/2){
            cout << cnt << endl;
            return 0;
        }
    }
    return 0;
}