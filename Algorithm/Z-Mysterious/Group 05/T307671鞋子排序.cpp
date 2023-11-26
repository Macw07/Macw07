#include <iostream>
#include <algorithm>
using namespace std;

int arr[10005];
char temp[10005];

int main(){
    int n;
    cin >> n;
    for (int i=0; i<2*n; i++){
        cin >> arr[i] >> temp[i];
    }
    sort(arr, arr+2*n);
    for (int i=0; i<2*n; i++){
        if (i%2) cout << arr[i] << " r" << endl;
        else cout << arr[i] << " l" << endl;
    }
    return 0;
}