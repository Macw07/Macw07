#include <iostream>
using namespace std;

int main(){
    int a, b, c, count=0;
    cin >> a >> b >> c;
    if (a < 60) count++;
    if (b < 60) count++;
    if (c < 60) count++;
    if (count == 1){
        cout << 1 << endl;
    } else{
        cout << 0 << endl;
    }
    return 0;
}