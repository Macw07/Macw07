#include <iostream>
using namespace std;

int n;
long long arr[105] = {0, 1, 2, 3};

int main(){
    cin >> n;
    for (int i=3; i<=n; i++){
        arr[i] = arr[i-1] + arr[i-2];
    }
    cout << arr[n] << endl;
    return 0;
}