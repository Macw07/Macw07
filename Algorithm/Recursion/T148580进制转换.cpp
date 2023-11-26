#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

string str;

int recursion(int n){
    if (n == 0) return 0;
    str += char(n%2)+'0';
    recursion(n/2);
    return 0;
}

int main(){
    int n;
    cin >> n;
    recursion(n);
    reverse(str.begin(), str.end());
    cout << str;
    return 0;
}