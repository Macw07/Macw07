#include <iostream>
using namespace std;

long long arr[105] = {0, 1, 2};

int main(){
    int n;
    cin >> n;
    for (int i=2; i<=n+1; i++) {
        arr[i] = arr[i-1] + arr[i-2] + arr[i-3];
    }
    cout << arr[n+1];
    return 0;
}