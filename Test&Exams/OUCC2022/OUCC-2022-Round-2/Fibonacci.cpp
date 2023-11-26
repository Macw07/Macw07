#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

long long a, b, arr[50];

bool check(long long num){
    if (num <= 9) return false;
    int k = num % 10;
    while(num){
        int r = num % 10;
        if (r != k){
            return false;
        }
        num /= 10;
    }
    return true;
}

int main(){
    cin >> a >> b;
    arr[0] = a;
    arr[1] = b;
    for (int i=2; i<25; i++){
        arr[i] = arr[i-1] + arr[i-2];
        if (check(arr[i])){
            cout << arr[i] << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}