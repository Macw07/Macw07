#include <iostream>
using namespace std;

int facorial(int n){
    if (n==1){
        return 1;
    }
    return facorial(n-1)*n;
}

int main(){
    int n;
    cin >> n;
    cout << facorial(n);
    return 0;
}