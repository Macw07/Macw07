#include <iostream>
using namespace std;

long long arr[500010] = {};

int main(){
    int n;
    cin >> n;
    arr[0] = 1;
    arr[1] = 3;
    arr[2] = 9;
    for (int i=3; i<=n; i++){
        arr[i] = 4*(i-1)+2+arr[i-1];
    }
    cout << arr[n];
    return 0;
}