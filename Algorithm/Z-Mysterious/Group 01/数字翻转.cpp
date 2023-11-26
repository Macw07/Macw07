#include <iostream>
using namespace std;

int main(){
    int sum=0;
    int n = 12;
    while(n){
        sum=sum*10+n%10;
        n /= 10;
    }  
    cout << sum;
}