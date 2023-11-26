#include <iostream>
using namespace std;

long long arr[15] = {1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628000};

int main(){
    int n;
    cin >> n;
    if (n==0){
        cout << "No";
        return 0;
    }
    // 每次找到最接近自己的那个阶乘
    for (int i=9; i>=0; i--){
        if (arr[i] <= n){
            // cout << i+1 << " ";
            n -= arr[i];
        }
    }
    if (n){
        cout << "No";
    } else{
        cout << "Yes";
    }
    return 0;
}