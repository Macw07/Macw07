#include <iostream>
using namespace std;

int arr[10005];

int main(){
    int n;
    int total = 0;
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> arr[i];
    }
    for (int i=0; i<n; i++){
        for (int j=i+1; j<n; j++){
            total = max(arr[j] - arr[i], total);
        }
    }
    cout << total;
    return 0;
}