#include <iostream>
#include <cmath>
using namespace std;

double ans;

double recursion(double x, double n){
    if (n == 1){
        return sqrt(1+x);
    }
    return sqrt((n)+recursion(x, n-1));
}   

int main(){
    double x, n;
    cin >> x >> n;
    printf("%.2f", recursion(x, n));
    return 0;
}