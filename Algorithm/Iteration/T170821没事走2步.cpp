#include <iostream>
#include <algorithm>
using namespace std;

long long arr[105] = {1, 3, 7, 17};

int main(){
    int n;
    cin >> n;
    for (int i=3; i<=n; i++){
        arr[i] = 2*arr[i-1]+arr[i-2];
    }
    cout << arr[n];
    return 0;
}