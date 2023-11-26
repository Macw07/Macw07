#include <iostream>
using namespace std;

int n;

int fib(int n){
    if (n == 1 || n == 0) return n;
    return fib(n-1)+fib(n-2);
}

int main(){
    cin >> n;
    cout << fib(n) << endl;
    return 0;
}

// 一维的斐波那契数列 & 递推
// #include <iostream>
// using namespace std;

// int main(){
//     int n;
//     cin >> n;
//     long long arr[100] = {0, 1, 1};
//     for (int i=2; i<=n; i++){
//         arr[i] = arr[i-1]+arr[i-2];
//     }
//     cout << arr[n] << endl;
//     return 0;
// }

// 零维的斐波那契数列 => 使用递归实现
// #include <iostream>
// using namespace std;

// int n;

// void fib(int k, int a, int b){
//     if (n == k){
//         cout << a << endl;
//         return;
//     }
//     int c = a+b;
//     fib(k+1, b, c);
// }

// int main(){
//     cin >> n;
//     fib(1, 1, 1);
//     return 0;
// }
