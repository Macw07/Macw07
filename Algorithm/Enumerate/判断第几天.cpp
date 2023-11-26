/* 输入某年某月某日，判断这一天是这一年的第几天？*/
#include <iostream>
using namespace std;

int main(){
    int year, month, day;
    cin >> year >> month >> day;
    int arrNY[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int arrLY[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int count = 0;
    if (year%4==0 && year%100 != 0 or year%400==0){
        for (int i=0; i <month-1; i++){
            count += arrLY[i];
        }
        count += day;
    } else{
        for (int i=0; i <month-1; i++){
            count += arrNY[i];
        }
        count += day;
    }
    cout << count;
}
