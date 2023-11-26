#include <iostream>
#include <algorithm>
using namespace std;

int n, q;

bool canCal(int h, int m){
    string str;
    bool flag = 0;
    if (m <= 9) flag = 1;
    if (m == 0) str += '0';
    while (m){
        str += (m % 10) + '0';
        m /= 10;
    }
    if (flag) str += '0';
    while (h){
        str += (h % 10) + '0';
        h /= 10;
    }
    reverse(str.begin(), str.end());
    int a = str[1] - str[0];
    for (int i=2; i<str.size(); i++){
        if (str[i] - str[i-1] != a) return false;
    }
    return true;
}

int count(int q){
    int total = 0;
    int h = 12, m = 0;
    while(q--){
        m += 1;
        if (m == 60){
            m = 0;
            h += 1;
        }
        if (h == 13) h = 1;
        // 判断是否可以构成等差数列
        if (canCal(h, m)) total += 1;
    }
    return total;
}

int main(){
    scanf("%d", &n);
    while(n--){
        scanf("%d", &q);
        printf("%d\n", count(q));
    }
    return 0;
}