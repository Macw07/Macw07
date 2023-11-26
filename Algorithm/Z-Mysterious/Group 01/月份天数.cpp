#include <iostream>
using namespace std;

int main(){
    int year, month;
    cin >> year >> month;
    bool leapYear = (year%4==0 && year%100 != 0 || year%400 == 0);
    int arr[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (leapYear && month>=2){
        cout << arr[month-1]+1;
    } else{
        cout << arr[month-1];
    }
    return 0;
}