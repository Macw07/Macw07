// 在n个数字当中，输出所有对子，对子依次为最大最小之和，第二大第二小之和，依次类推，直到0个元素或者1个元素

#include <iostream>
using namespace std;

int arr[1005] = {};

int main(){
    int num;
    cin >> num;
    for (int i=0; i<num; i++){
        cin >> arr[i];
    }
    for (int i=0; i<num-1; i++){
        for (int j=0; j<num-i-1; j++){
            if (arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
            }
        }
    }
    int times = num/2;
    int sum = 0;
    for (int i=0; i<times; i++){
        sum = arr[i] + arr[num-i-1];
        cout << sum << endl;
    }
}