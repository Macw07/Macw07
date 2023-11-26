/* 小码酱要过生日了，小码君准备攒钱给她买礼物，
已知他第一天攒一块钱，第二天攒两块钱，第三天攒三块钱，第四天攒四块钱...，
请问到第几天的时候，攒的总钱数S会达到或者超过礼物金额N？ */

#include <iostream>
using namespace std;

int main(){
    int target;
    cin >> target;
    int sum = 1;
    int date = 0;
    while (sum<target){
        date++;
        sum += date;
    }
    cout << date;
}