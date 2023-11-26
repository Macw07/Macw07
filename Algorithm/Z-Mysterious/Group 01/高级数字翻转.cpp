// 给定一个整数，请将该数各个位上数字反转得到一个新数。
// 新数也应满足整数的常见形式，即除非给定的原数为零，否则反转后得到的新数的最高位数字不应为零（参见样例2）。

#include <iostream>
using namespace std;

int main(){
    int number, result=0;
    cin >> number;
    while (number){
        result = result*10+number%10;
        number /= 10;
    }
    cout << result;
}