#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr[1005];

int main(){
    // freopen("Data/testcase20.in", "r", stdin);
    // freopen("Data/testcase20.out", "w", stdout);
    cin >> n;
    for (int i=1; i<=n; i++){
        cin >> arr[i];
    }
    sort(arr+1, arr+n+1);
    for (int i=1; i<n; i++){
        int maximum = arr[n];
        int minimum = arr[1];
        arr[1] = maximum / minimum;
        n -= 1;
        sort(arr+1, arr+n+1);
    }
    cout << arr[1] << endl;
    return 0;
}