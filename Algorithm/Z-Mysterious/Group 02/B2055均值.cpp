#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    double total = 0;
    for (int i=0; i<n; i++){
        double t;
        cin >> t;
        total += t;
    }
    double ans = total/n;
    printf("%.4f", ans);
    return 0;
}