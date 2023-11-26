#include <iostream>
#include <algorithm>
using namespace std;

int arr[1005];

int main(){
    int n, total = 0, m = -1000000;
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> arr[i];
        m = max(m, arr[i]);
    }
    for (int i=0; i<n; i++){
        if (arr[i] != m) total += arr[i];
    }
    cout << total << endl;
    return 0;
}