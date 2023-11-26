#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int n;
    cin >> n;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=i; j++){
            printf("%d ^ %d = %d ", i, j, int(pow(i, j)));
        }
        printf("\n");
    }
    return 0;
}