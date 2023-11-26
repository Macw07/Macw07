#include <iostream>
#include <cmath>
using namespace std;

long long arr[10005] = {0, 0, 1};

long long fact(int n){
    if (n == 1) return 1;
    return fact(n-1)*n;
}

int main(){
    int n;
    cin >> n;
    for (int i=3; i<=n; i++){
        arr[i] = (i-1)*(arr[i-1]+arr[i-2]);
    }
    double ans = double(arr[n])/fact(n);
    printf("%.2f%%", ans*100);
    return 0;
}
