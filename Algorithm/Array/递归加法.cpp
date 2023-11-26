// 通过递归实现加法

#include <iostream>
using namespace std;

int sum = 0;

void recursion(int number){
    // cout << number << endl;
    if (number<=0){
        return;
    }
    sum += number;
    recursion(number-1);
    return;
}

int main(){
    int number = 10;
    recursion(number);
    cout << sum << endl;
}