#include <iostream>
#include <algorithm>
using namespace std;

int arr[10005] = {};

int main(){
    int n, m;
    cin >> n >> m;
    for (int i=0; i<n; i++){
        cin >> arr[i];
    }
    sort(arr, arr+n);
    int total=0;
    for (int i=0; i<n; i++){
        if (total >= m){
            break;
        }
        total += arr[i];
    }
    cout << total;
    return 0;
}