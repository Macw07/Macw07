// 在整数数组中，如果一个整数的出现频次和它的数值大小相等，我们就称这个整数为「幸运数」。

#include <iostream>
using namespace std;

int main(){
    int n, t;
    cin >> n;
    int arr[n];
    for (int i=0; i<n; i++){
        arr[i] = 0;
    }
    for (int i=0; i<n; i++){
        cin >> t;
        arr[t-1] ++;
    }
    bool flag=0;
    int max = 0;
    for (int i=0; i<n; i++){
        if (i+1 == arr[i] && arr[i] != 0){
            if (arr[i] > max){
                flag=1;
                max = arr[i];
            }
        }
    }
    if (flag) {cout << max << endl;}
    else {cout << -1 << endl;}
}