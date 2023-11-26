#include <iostream>
using namespace std;

int main(){
    string str;
    int sum=0, count=1;
    cin >> str;
    for (int i=0; i<str.size()-1; i++){
        if (str[i] == '-') continue;
        sum += (str[i]-'0')*count;
        count++;
    }
    sum %= 11;
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