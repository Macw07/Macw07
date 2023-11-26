#include <iostream>
#include <algorithm>
using namespace std;

// 整体思路，找到一个最长的下陷的路，然后进行填平
int n, total = 0;
int arr[100005];

/*
假设现在有一个坑，但旁边又有一个坑。
你肯定会选择把两个同时减1；
那么小的坑肯定会被大的坑“带着”填掉。
大的坑也会减少a[i]-a[i-1]的深度，可以说是“免费的”；
所以这样贪心是对的；
*/

int main(){
    scanf("%d", &n);
    for (int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    total += arr[0];
    for (int i=1; i<n; i++){
        if (arr[i] > arr[i-1]) total += arr[i]-arr[i-1];
    }
    // while(1){
    //     bool flag = 0;
    //     bool begin = 0;
    //     for (int i=0; i<n; i++){
    //         if (!begin && arr[i] != 0){
    //             // 第一个不为0的数字
    //             begin = 1;
    //         }
    //         if (begin == 1) {
    //             if (arr[i] == 0){
    //                 break;
    //             }
    //             arr[i]--;
    //         }
    //     }
    //     total++;
    //     if (begin == 0) break;
    // }
    printf("%d", total);
    return 0;
}