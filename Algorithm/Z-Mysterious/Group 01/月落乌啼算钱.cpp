#include <iostream>
#include <cmath>
using namespace std;

int main(){
    double n;
    cin >> n;
    double ans =  (pow(((1+sqrt(5))/2),n)-pow(((1-sqrt(5))/2),n))/sqrt(5);
    printf("%.2f", ans);
    return 0;
}