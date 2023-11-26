#include <iostream>
#include <cmath>
using namespace std;

bool check(double mid){
    double left = (2*mid-9)*(mid-5);
    double right = 300;
    return left <= right;
}
int main(){
    int ans = 0;
    double l=-1, r=10000;
    while(r-l > 0.0001){
        ans++;
        double mid = (l+r)/2;
        if (check(mid)){
            l = mid;
        } else{
            r = mid;
        }
        cout << l << " " << r << endl;
    } 
    cout << ans << endl;
    cout << r << endl;  
}