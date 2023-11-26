#include <iostream>
using namespace std;

int n, k, arr[100000005];

int main(){
    cin >> n;
    for (int i=1; i*i<=n; i++){
        if (n % i == 0) {
            printf("%d ", i);
            arr[++k] = n / i;
        }
    }
    for (int i=k; i>=1; i--){
        printf("%d ", arr[i]);
    }
    return 0;
}