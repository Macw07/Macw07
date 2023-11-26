/* 欧阳同学想要大家帮他一个忙，他想找出很多数中出现奇数次的数字，如果一个数出现了奇数次，其他数都是偶数次，
请输出这个数字，如果不能找到，请输出No. （注意，这些数一定 <=500）*/
#include <iostream>
using namespace std;

int arr[505] = {};

int main(){
    int n;
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> arr[i];
    }
    bool flag = false;
    int num = 0;
    for (int i=0; i<n; i++){
        int count = 0;
        for (int j=0; j<n; j++){
            if (arr[i]==arr[j]){
                count += 1;
            }
        }
        if (count % 2 == 1 && !flag) {
            num = arr[i];
            flag = true;
        } else if (count % 2 == 1 && flag){
            flag = false;
        }
    }
    if (!flag){
        cout << "No.";
    } else{
        cout << num;
    }
}