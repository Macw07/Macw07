#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

double a, b, c, d;

int main(){
    scanf("%lf %lf %lf %lf", &a, &b, &c, &d);
    for (double i=-100; i<=100; i+=0.001){
        if (fabs(i*i*i*a+i*i*b+i*c+d)<0.0001){
            printf("%.2lf ", i);
        }
    }
    return 0;
}