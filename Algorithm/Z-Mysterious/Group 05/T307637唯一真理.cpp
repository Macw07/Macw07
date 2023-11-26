#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

int tt, n;
bool flag;
int nums[10];
int ans[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 19, 29, 39, 49, 59, 69, 79, 89, 189, 289, 389, 489, 589, 689, 789, 1789, 2789, 3789, 4789, 5789, 6789, 16789, 26789, 36789, 46789, 56789, 156789, 256789, 356789, 456789, 1456789, 2456789, 3456789, 13456789, 23456789, 123456789, -1, -1, -1, -1, -1};
// 看样子，所有的bug都处于：column 1, read 9, expected 1.
// 原因：每个数字只能使用一次

bool check(int k){
    for (int i=1; i<=9; i++){
        if (nums[i] > 1) return false;
    }
    return true;
}

// 数位拆分
bool split(int k){
    memset(nums, 0, sizeof nums);
    int sum = 0;
    while(k){
        sum += k % 10;
        nums[k%10]++;
        k /= 10;
    }
    return sum == n;
}

int main(){
    cin >> tt;
    while(tt--){
        cin >> n;
        cout << ans[n] << endl;
        // tt++;
        // n = tt;
        // flag = false;
        // // 确定上下限
        // if (n > 45) {cout << -1 << endl; continue;}
        // for (int i=0; i<=123456789; i++){
        //     if (split(i) && check(i)){
        //         cout << i << ", ";
        //         flag = true;
        //         break;
        //     }
        // }
        // if (!flag) cout << -1 << endl;
    }
    return 0;
}