#include <iostream>
#include <algorithm>
using namespace std;

int f, n, total = 0;

bool check(int n){
    // 将n转换成字符串并判断
    string s, s2;
    // if (n / 10 % 10 == 0) s += '0';
    // else if (n / 100 % 10 == 0) s += '0';
    while(n){
        if (n % 10 == 6) s += '9';
        else if (n % 10 == 9) s += '6';
        else if (n % 10 == 1) s += '1';
        else if (n % 10 == 8) s += '8';
        else if (n % 10 == 0) s += '0';
        else s += 'x';
        s2 += n % 10 + '0';
        n /= 10;
    }
    reverse(s2.begin(), s2.end());
    // cout << s << endl;
    // cout << s2 << endl;
    return s == s2;
}

int main(){
    cin >> f >> n;
    for (int i=1; i<=f; i++){
        for (int j=1; j<=n; j++){
            if (check(i*100+j)){
                total++;
            }
        }
    }
    // cout << check(619) << endl;
    cout << total << endl;
    return 0;
}