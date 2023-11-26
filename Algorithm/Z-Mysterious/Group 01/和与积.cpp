// 输入一个整数S，表示两个素数的和，求两个素数的积的最大值

#include <iostream>
using namespace std;

bool isPrime(int number){
    for (int i=2; i*i<number; i++){
        if (number%i == 0){
            return false;
        }
    }
    return true;
}

int main(){
    int S, pro;
    cin >> S;
    for (int i=2; i<(S/2); i++){
        bool a = isPrime(i);
        bool b = isPrime(S-i);
        if (a && b){
            pro = i * (S-i);
            // cout << pro << endl;
        }
    }
    cout << pro; 
}
