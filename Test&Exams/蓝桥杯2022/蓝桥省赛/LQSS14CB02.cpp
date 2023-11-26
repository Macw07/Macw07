#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

long long bg, ed;

string convert(long long n){
    string ans;
    while(n){
        ans += ((n % 10)+'0');
        n /= 10;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

bool check(string s){
    string ori = s;
    long long ans = 0, len = s.size();
    for (long long i=0; i<len; i++){
        ans = ans + pow(s[i]-'0', 4);
    }
    if (convert(ans) == ori) return true;
    return false;
}

int main(){
    cin >> bg >> ed;
    for (long long i=bg; i<=ed; i++){
        string number = convert(i);
        if (check(number)){
            cout << i << " ";
        }
    }
    return 0;
}