#include <iostream>
using namespace std;

int main(){
    int money, t=10;
    cin >> money;
    int total=money, empty=money, cover=money;
    while(1){
        int empty_switch = empty / 2;
        total += empty_switch;
        empty = empty % 2 + empty_switch;
        cover +=  empty_switch;

        int cover_switch = cover / 3;
        total += cover_switch;
        empty += cover_switch;
        cover = cover % 3 + cover_switch;

        if (cover <= 2 && empty <= 1) break;
    }
    cout << total << endl;
    return 0;
}