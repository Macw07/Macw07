#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n, arr[5] = {};
    cin >> n;
    for (int i=0; i<n; i++){
        int t;
        cin >> t;
        arr[t]++;
    }
    cout << min(n-arr[1], min(n-arr[2], n-arr[3])) << endl;
    return 0;
}
