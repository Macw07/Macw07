#include <iostream>
#include <algorithm>
using namespace std;

bool compare(int a, int b){
    return a>b;
}

int main(){
    int arr[5] = {1, 9, 2, 8, 5};
    sort(arr, arr+5, compare);  // 三个参数 1. 首地址; 2. 尾地址; 3. 比较函数
    for (int i=0; i<5; i++){
        cout << arr[i] << " ";
    }
    sort(arr, arr+5, greater<int>());
    sort(arr, arr+5, less<int>());
    return 0;
}