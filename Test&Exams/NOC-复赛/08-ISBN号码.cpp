#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int main(){
    string str;
    int ans = 0, cnt = 1;
    cin >> str;
    for (int i=0; i<str.size()-1; i++) {
        if (str[i] == '-') continue;
        ans = ans + ((str[i]-'0') * cnt);
        cnt += 1;
    }
    int sum = ans % 11;
    int len = str.size()-1;
    if (str[len]-'0' == sum){
        cout << "Right";
        return 0;
    } else if(sum == 10 && str[len]=='X'){
        cout << "Right";
        return 0;
    } else{
        if (sum == 10){
            str[len] = 'X';
            cout << str;
            return 0;
        } else{
            str[len] = sum+'0';
            cout << str;
            return 0;
        }
    }
    return 0; 
}