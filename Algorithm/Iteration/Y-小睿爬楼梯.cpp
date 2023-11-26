#include <iostream>
using namespace std;

long long arr[1005] = {0, 0, 1, 1};

int main(){
    int n;
    cin >> n;
    for (int i=4; i<=n; i++){
        arr[i] = arr[i-2]+arr[i-3];
    }
    cout << arr[n];
    return 0; 
}