#include <iostream>
#include <algorithm>
using namespace std;

double a, b, c;

double find_max(double a, double b, double c){
    return max(max(a, b), c);
}

int main(){
    cin >> a >> b >> c;
    double ans = find_max(a, b, c)/(find_max(a+b, b, c)*find_max(a, b, b+c));
    printf("%.3lf", ans);
    return 0;
}