// 每一个数码在计数的过程中出现过多少次？

#include <iostream>
using namespace std;

int arr[10] = {};

int main(){
    int begin, end;
    cin >> begin >> end;
    for (int i=begin; i<=end; i++){
        int number = i;
        while (number){
            arr[number%10]++;
            number /= 10;
        }
    }
    for (int i=0; i<10; i++){
        cout << arr[i] << " ";
    }
    return 0;
}