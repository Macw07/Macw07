#include <iostream>
// 需要引入cmath头文件以使用sqrt函数。
#include <cmath>
using namespace std;

double x, n;

double f(double x, double n){
    // 最小问题，可以直接求解。
    if (n == 1){
        return sqrt(x + 1);
    }
    // 递归调用操作。
    return sqrt(n + f(x, n-1));
}

int main(){
    cin >> x >> n;
    printf("%.2lf\n", f(x, n));
    return 0;   
}