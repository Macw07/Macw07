#include <iostream>
using namespace std;

int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool leap(int year){
    return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}

int main(){
    int yy, mm, dd;
    int y=2022, m=12, d=1, ss=4;
    int total = 0;
    cin >> yy >> mm >> dd;

    while(1){
        // 一直累加日期直到那一天就可以了吧（so sad）
        if (yy == y && mm == m && dd == d) break;
        // printf("%d %d %d\n", y, m, d);

        if (leap(y)) days[2] = 29;
        else days[2] = 28;

        if (d != days[m]){
            d++;
            total++;
        } else{
            if (m != 12){
                m++;
            } else{
                m = 1;
                y++;
            }
            d = 1;
            total++;
        }
        ss++;
        if (ss == 8){
            ss = 1;
        }
    }
    printf("%d\n", total);
    printf("*%d\n", ss);
    return 0;
}