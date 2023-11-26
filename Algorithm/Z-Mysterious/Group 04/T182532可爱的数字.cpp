#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    string str;
    for (int i=1; i<=n; i++){
        str += i+'0';
    }
    cout << str;
    return 0;
}