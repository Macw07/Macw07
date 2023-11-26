#include <iostream>
using namespace std;

int main(){
    double n, total=0, last;
    cin >> n;
    last = 2;
    total += last;
    int times=1;
    while (total<n){
        times++;
        last = last*0.98;
        total += last;
    }
    cout << times;
    return 0;
}