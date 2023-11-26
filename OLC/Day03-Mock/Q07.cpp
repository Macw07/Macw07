#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

ll n, num, i;
string str;

int main(){
    cin >> str >> n;
    num = str.length();
    while(num < n){
        i = num;
        while(n > i) i *= 2;
        i /= 2;
        n -= (i+1);
        if (n == 0) n = i;
    }
    cout << str[n-1];
    return 0;
}

