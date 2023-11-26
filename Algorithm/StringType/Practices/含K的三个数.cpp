/* 输入两个正整数 m 和 k，其中1 < m < 100000，1 < k < 5 ，判断 m 能否被19整除，且恰好含有k个3，如果满足条件，则输出YES，否则，输出NO。

例如，输入： 43833 3 满足条件，输出YES。

如果输入： 39331 3 尽管有3个3，但不能被19整除，也不满足条件，应输出NO。*/
#include <iostream>
using namespace std;

int main(){
    int number;
    int K;
    cin >> number >> K;
    int count = 0;
    int n = number;
    while (number>0){
        number = number / 10;
        count += 1;
    }
    int arr[count];
    int pro = 1;
    int res;
    for (int i=0; i<count; i++){
        res = (n / pro)%10;
        pro *= 10;
        arr[i] = res;
    }
    int count_3 = 0;
    for (int i=0; i < count; i++){
        if (arr[i] == 3){
            count_3++;
        };
    }
    // cout << n << n % 19 << count_3 << K << endl;
    if (n % 19 == 0 and count_3 == K){
        cout << "YES";
    } else {
        cout << "NO";
    }
}