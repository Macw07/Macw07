#include <iostream>
using namespace std;

int n;
long long arr[105] = {1, 3, 9};

int main(){
    cin >> n;
    for (int i=2; i<=n; i++){
        // arr[i] = 4*(i-1)+2+arr[i-1];
        arr[i] = (4 * i) + arr[i-1] - 2;
    }
    cout << arr[n] << endl;
    return 0;
}