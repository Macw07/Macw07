#include <iostream>
using namespace std;

int main(){
    double n, ans;
    cin >> n;
    if (n >= 0 && n < 5){
        ans = n * -1 + 2.5;
    } else if (n < 10){
        ans =  2-1.5*(n-3)*(n-3);
    } else{
        ans =  n/2 - 1.5;
    }
    printf("%.3f", ans);
    return 0;
}
