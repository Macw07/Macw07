#include <iostream>
using namespace std;

int main(){
    int year;
    cin >> year;
    bool res = (year%4==0 && year%100 != 0 or year%400 == 0);
    cout << res;
    return 0;
}