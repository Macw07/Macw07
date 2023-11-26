#include <iostream>
using namespace std;

long long arr[1005] = {3, 6, 6};

int main(){
    int n;
    cin >> n;
    for (int i=3; i<=n; i++){
        arr[i] = arr[i-1]+arr[i-2]*2;
    }
    cout << arr[n-1];
    return 0;
}