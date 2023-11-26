#include <iostream>
using namespace std;

int main(){
    int a, b, t=0;
    cin >> a >> b;
    while(a && b){
        t++;
        if (a > b){
            b += 1;
            a -= 2;
        } else{
            a += 1;
            b -= 2;
        }
    }
    cout << t;
    return 0;
}