#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n;
    double sum;
    cin >> n;
    for (int i=0;i<n; i++){
        double t;
        cin >> t;
        sum += t;
    }
    sum += sum * 0.05;
    // cout << sum << endl;
    printf("%.2lf\n", sum/(n-1));
    return 0;
}