#include <iostream>
using namespace std;

bool isPrime(int num);

int main(){
    int number, result=0;
    cin >> number;
    bool a = isPrime(number);
    while (number){
        result = result*10+number%10;
        number /= 10;
    }
    bool b = isPrime(result);
    if (a && b){
        cout << "Yes";
    } else{
        cout << "No";
    }
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