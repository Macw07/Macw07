#include <iostream>
using namespace std;

int main(){
    int n, sum=0;
    cin >> n;
    n /= 10;
    sum += n%10;
    n /= 10;
    sum += n%10;
    printf("%d", sum);
    return 0;
}