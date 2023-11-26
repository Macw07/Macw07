#include <iostream>
#include <algorithm>
using namespace std;

int n;
long long arr[105];

int main(){
    cin >> n;
    arr[1] = 1;
    arr[2] = 2;
    arr[3] = 3;
    for (int i=4; i<=n; i++){
        arr[i] = arr[i-1] + arr[i-2];
    }
    cout << arr[n] << endl;
    return 0;
}