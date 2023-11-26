#include <iostream>
using namespace std;

int main(){
    long long n, arr[105] = {1, 2, 3, 4, 6};
    cin >> n;
    for (int i=5; i<=n; i++){
        arr[i] = arr[i-3]+arr[i-1];
    }
    cout << arr[n-1];
    return 0;
}