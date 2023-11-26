#include <iostream>
using namespace std;

int main(){
    int n;
    long long total=1;
    cin >> n;
    while(n){
        total *= n;
        n--;
    }
    cout << total; 
    return 0;
}