#include <iostream>
using namespace std;

void convert(int n){
    if (n / 2 == 0){
        cout << n % 2;
        return ;
    }
    convert(n/2);
    cout << n % 2;
    return ;
}

int main(){
    int n;
    cin >> n;
    convert(n);
    return 0;
}