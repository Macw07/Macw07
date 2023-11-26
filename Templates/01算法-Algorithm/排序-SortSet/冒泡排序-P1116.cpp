#include <iostream>
using namespace std;

// 同时，这道题可以通过逆序对来实现

int n, arr[10005];

int main(){
    cin >> n;
    int count = 0;
    for (int i=0; i<n; i++){
        cin >> arr[i];
    }
    for (int i=0; i<n-1; i++){
        for (int j=0; j<n-i-1; j++){
            if (arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
                count += 1;
            }
        }
    }
    cout << count;
    return 0;
}