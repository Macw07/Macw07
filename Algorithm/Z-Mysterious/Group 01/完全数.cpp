/* 完全数：不包括他自己的因子之和等于它本身的自然数，如6=1+2+3 */

#include <iostream>
using namespace std;

int main(){
    int begin = 0;
    int end = 0;
    bool flag = 0;
    cin >> begin >> end;
    for (int n=begin; n<=end; n++){
        int sum = 0;
        for (int i=1; i<n; i++){
            if (n % i == 0){
                sum += i;
            }
        }
        if (sum == n){
            flag = 1;
            cout << n << endl;
        } 
    }
    if (!flag){
            cout << 0;
        }
}