#include <iostream>
#include <algorithm>
using namespace std;

// 一道非常棒的前缀和练习题

int n;
long long arr[2000005];

int main(){
    cin >> n;
    for (int i=1; i<=n; i++){
        arr[i] = arr[i-1] + i; 
    }
    for (int i=1; i<=n; i++){
        for (int j=i+1; j<=n; j++){
            // 前缀和模板题
            if (arr[j] - arr[i-1] == n){
                cout << i << ' ' << j << endl;
            } 
            // 特殊判断
            if (arr[j] - arr[i-1] > n) break;  // 提前终止
        }
    }
    return 0;
}