/* 如果一个自然数是素数,且它的数字位置经过翻转后仍为素数,则称为绝对素数,
例如13,请计算1-n之间有多少个绝对素数. */
#include <iostream>
using namespace std;

bool isPrime(int num);

int main()
{
    int total = 0;
    cin >> total;
    int count = 0;

    for (int i=2; i<total; i++){
        int sum = 0;
        int n = i;
        while(n){
            sum=sum*10+n%10;
            n /= 10;
        }
        bool a = isPrime(i);
        bool b = isPrime(sum);
        if (a && b){
            // cout << i << " True" << endl;
            count ++;
        }
    }
    cout << count;
    return 0;
}

bool isPrime(int num){
    bool flag = 1;
    for (int i = 2; i * i <= num; i++)
    {
        if (num % i == 0)
        {
            flag = 0;
            // cout << num << " isNotPrime" << endl;
            break;
        }
    }
    // if (flag){cout << num << " isPrime" << endl;}
    return flag;
}