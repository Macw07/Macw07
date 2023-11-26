#include <iostream>
using namespace std;

int arr[1005] = {};

int main(){
    int x, y, z;
    cin >> x >> y >> z;
    for (int i=0; i<=x; i++){
        arr[i] = 1;
    }
    for (int i=x+1; i<=z+1; i++){
        arr[i] = arr[i-1] + arr[i-x-2]*y;
    }
    cout << arr[z];
    return 0;
}