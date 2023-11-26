#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;

long long arr[1005] = {};
long long arr2[1005] = {};

int main(){
    string str;
    int n=0, a=0, b=0, t, c=0;
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> arr[i];
    }
    for (int i=1; i<n; i++){
        arr2[i] = abs(arr[i]-arr[i-1]);
    }
    sort(arr2, arr2+n);
    // cout << arr2[1] << arr2[2] << arr2[3];
    for (int i=1; i<n; i++){
        if (arr2[i] != i) {
            cout << "Not jolly";
            return 0;
        }
    }
    cout << "Jolly" << endl;
    return 0;
}