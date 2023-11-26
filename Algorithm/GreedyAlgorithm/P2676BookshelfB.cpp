#include <iostream>
#include <algorithm>
using namespace std;

int arr[20005] = {};

bool temp(int a, int b){
    return a>b;
}

int main(){
    int n, height, count=0;
    cin >> n >> height;
    for (int i=0; i<n; i++){
        cin >> arr[i];
    }
    sort(arr, arr+n, temp);
    int i=0;
    while (count < height && i<n){
        count += arr[i];
        i++;
    }
    cout << i;
    return 0;
}