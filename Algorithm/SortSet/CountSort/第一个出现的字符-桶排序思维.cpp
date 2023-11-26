// 给定一个只包含小写字母的字符串，请你找到第一个仅出现一次的字符。如果没有，输出no。

#include <iostream>
using namespace std;

int arr[122] = {};

int main(){
    string str;
    getline(cin, str);
    for (int i=0; i<str.size(); i++){
        arr[str[i]]++;
    }
    for (int i=0; i<122; i++){
        if (arr[i]==1){
            cout << char(i);
            break;
        }
    }
}
