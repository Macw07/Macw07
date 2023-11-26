#include <iostream>
using namespace std;

int arr[1005] = {};
// 递推公式 P(n) = P(n-1)+(n-1)+1 = P(n-1)+n

int main(){
    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 4;
    int n;
    cin >> n;
    for (int i=3; i<=n; i++){
        arr[i] = arr[i-1]+i;
    }
    cout << arr[n];
    return 0;
}