#include <iostream>
#include <cmath>
using namespace std;

double n, m, k;
double l, r;

bool check(double mid){
    // 看看利率为mid时，是否可以还清债务
    double total = 0;
    double month = n;
    for (int i=1; i<=k; i++){
        total += m - (month * mid);
        month -= m - (month * mid);
    }
    return total >= n;
}

int main(){
    cin >> n >> m >> k;
    l=0, r=n;
    while(r-l > 0.0005){
        double mid = (l+r)/2;
        if (check(mid)){
            l = mid;
        } else{
            r = mid;
        }
    }
    printf("%.1f", l*100);
    return 0;
}