#include <iostream>
using namespace std;

int main(){
    int n, cnt = 0;
    cin >> n;
    while(n > 1){
        if (n % 3 == 0) n /= 3;
        else {n /= 3; n++;}
        cnt++;
    }
    cout << cnt << endl;
    return 0;
}