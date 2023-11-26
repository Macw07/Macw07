// 已知正整数 n 是两个不同的质数的乘积，试求出两者中较大的那个质数
#include <iostream>
using namespace std;

// 质因数分解，找出一个最大的质数
int main()
{
    int n;
    cin >> n;
    for (int i = 2; i * i <= n; i++){
        if (n%i == 0){
            cout << n/i;
            break;
        }
    }
        return 0;
}