#include <iostream>
#include <cmath>
using namespace std;

long long arr[1005][1005] = {};

int main(){
    int r;
    cin >> r;
    for (int i=0; i<r; i++){
        for (int j=0; j<i+1; j++){
            cin >> arr[i][j];
        }
    }
    for (int i=r-2; i>=0; i--){
        for (int j=0; j<i+1; j++){
            arr[i][j] += max(arr[i+1][j], arr[i+1][j+1]);
        }
    }
    cout << arr[0][0] << endl;
    return 0;
}