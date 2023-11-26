#include <iostream>
using namespace std;

void hypothesis(long long n){
    // n=1，即完成题目要求，则停止递归函数。
    if (n == 1) return ;

    // 判断n的奇偶性，作出判断。
    if (n % 2 == 1){
        cout << n << "*3+1=" << n*3+1 << endl;
        hypothesis(n * 3 + 1); 
    } else{
        cout << n << "/2=" << n/2 << endl;
        hypothesis(n / 2);
    }
    return ;
}

int main(){
    long long n; cin >> n;
    hypothesis(n);
    cout << "End" << endl;
    return 0;
}