/* 输入一个偶数 N，
验证 4∼N 所有偶数是否符合哥德巴赫猜想：
任一大于2 的偶数都可写成两个质数之和。
如果一个数不止一种分法，则输出第一个加数相比其他分法最小的方案。 */

#include <iostream>
using namespace std;

bool isPrime(int num1, int num2){
    bool flag = 1;
    for (int i=2; i*i <= num1; i++){
        if (num1 % i == 0){
            flag = 0;
        }
    }
    for (int i=2; i*i <= num2; i++){
        if (num2 % i == 0){
            flag = 0;
        }
    }
    return flag;
}

int main(){
    int N;
    cin >> N;
    for (int num=4; num<=N; num+=2){
        for (int i=2; i<=num; i++){
            bool res = isPrime(i, num-i);
            if (res){
                cout << num << "=" << i << "+" << num-i << endl;;
                break;
            }
        }
    }
}
