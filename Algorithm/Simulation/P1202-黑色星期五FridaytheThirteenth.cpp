#include <iostream>
using namespace std;

int cnt[10];
int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int n, yy, mm, dd, current;

inline bool isLeap(int year){
    return ((year % 4 == 0) && (year % 100 != 0 || year % 400 == 0));
}

int main(){
    cin >> n;
    yy = 1900;
    mm = dd = 1;
    current = 0;
    while(yy != 1900 + n - 1 || mm != 12 || dd != 31){
        if (dd == 13){
            cnt[current] += 1;
        }
        current += 1;
        current %= 7;
        dd += 1;
        bool flag = 0;
        if (mm == 2 && isLeap(yy)) flag = 1;
        if (dd > days[mm] + flag){
            dd = 1;
            mm += 1;
        }
        if (mm > 12){
            mm = 1;
            yy += 1;
        }
    }
    cout << cnt[5] << " " << cnt[6] << " ";
    for (int i=0; i<5; i++) cout << cnt[i] << " ";
    return 0;
}