#include <iostream>
using namespace std;

int main(){
    long long a, b, ex;
    cin >> a >> b >> ex;
    cout<<(a+(ex-1)*(b-a)+a)*ex/2;
    return 0;
}