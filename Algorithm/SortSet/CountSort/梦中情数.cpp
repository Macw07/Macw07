// Bessie 处于半梦半醒的状态。过了一会儿，她意识到她在数数，不能入睡。
// Bessie 的大脑反应灵敏，仿佛真实地看到了她数过的一个又一个数。她开始注意每一个数码（0…9）：每一个数码在计数的过程中出现过多少次？

#include <iostream>
using namespace std;

// int arr[100] = {};
int times[10] = {};

int isContain(int number, int t);

int main(){
    int begin, end;
    cin >> begin >> end;
    for (int i=begin; i<=end; i++){
        for (int k=0; k<10; k++){
            // cout << i << " " << k;
            isContain(i, k);
        }
    }
    for (int i=0; i<10; i++){
        cout << times[i] << " ";
    }
}

int isContain(int number){
    int c = number;
    while (number){
        times[number%10-1]++;
        number /= 10;
    }
    return 0;
}
