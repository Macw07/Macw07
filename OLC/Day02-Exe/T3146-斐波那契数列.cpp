#include <iostream>
using namespace std;

long long arr[105] = {0, 1};

int main(){
    int n;
    cin >> n;
    if (n >= 1) cout << 1 << " "; 
    for (int i=2; i<=n; i++) {
		arr[i] = arr[i-1] + arr[i-2];
        cout << arr[i] << " ";
    }
    return 0;
}