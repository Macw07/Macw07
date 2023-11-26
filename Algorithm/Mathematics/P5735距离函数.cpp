#include <iostream>
#include <cmath>

int main(){
    double a, b, c, d, e, f, circumference=0;
    std::cin >> a >> b >> c >> d >> e >> f;
    circumference += sqrt(pow((c-a),2)+pow((d-b), 2));
    circumference += sqrt(pow((e-c),2)+pow((f-d), 2));
    circumference += sqrt(pow((a-e),2)+pow((b-f), 2));
    printf("%.2f", circumference);
}