#include <iostream>
using namespace std;

int total;
int x, y, product;

int max_factor(int a, int b){
    if (a % b == 0){
        return b;
    }
    return max_factor(b, a % b);
}

int min_product(int a, int b){
    return a/x*b;
}

// 两个数的积等于它们最大公约数和它们最小公倍数的积相同

int main(){
    cin >> x >> y;
    product = x * y;
    for (int i=x; i<=y; i++){
        if (max_factor(i, product/i) == x){
            if (min_product(i, product/i) == y){
                total += 1;
            }
        }
    }
    cout << total << endl;
    return 0;
}