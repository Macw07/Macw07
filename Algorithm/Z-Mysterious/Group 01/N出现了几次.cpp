/* 一个数字出现了几次？ */

#include <iostream>
using namespace std;

int isContain(int number, int t);

int main(){
    int n=0;
    int target=0;
    cin >> n >> target;
    int count=0;
    int result;
    for (int i=1; i<=n; i++){
        result=0;
        result = isContain(i, target);
        count += result;
        // if (result){
        //     cout << i << " ";
        // }
    }
    cout << count << endl;
    return 0;
}

int isContain(int number, int t){
    int c = number;
    int cont = 0;
    while (number){
        if (number % 10 == t){
            cont++;
        }
        number /= 10;
    }
    return cont;
}