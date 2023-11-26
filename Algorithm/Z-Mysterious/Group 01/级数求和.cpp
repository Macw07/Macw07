#include <iostream>
using namespace std;

int main(){
    double k, n=1;
    double sum=1;
    cin >> k;
    while (sum <= k){
        n++;
        sum += 1/n;
    }
    cout << n;
    return 0; 
}