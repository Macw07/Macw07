#include <iostream>
using namespace std;

int arr[200005] = {};

int main(){
    int n;
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> arr[i];
    }
    int temp=0, total=-0x7f7f;
    for (int i=0; i<n; i++){
        temp += arr[i];
        // 稳定更新数组
        if (temp > total){
            total = temp;
        }
        // 如果是一个负数，说明是负增长的情况，就需要舍弃
        if (temp <= 0){
            temp = 0;  // 把temp归位0 
        }
    }
    cout << total;
    return 0;
}