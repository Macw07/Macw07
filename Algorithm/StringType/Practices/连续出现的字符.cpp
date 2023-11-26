// 给定一个字符串，在字符串中寻找第一个连续出现次数不低于 k 次的字符。

#include <iostream>
using namespace std;

int main(){
    int number, max_length=1;
    string str;
    cin >> number >> str;
    bool flag = false;
    for (int i=0; i<str.size(); i++){
        if (str[i] == str[i+1]){
            max_length += 1;
        } else{
            max_length = 1;
        }
        if (max_length>=number){
            cout << str[i];
            flag = true;
            return 0;
        }
    }
    cout << "No";
}