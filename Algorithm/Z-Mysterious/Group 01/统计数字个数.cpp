/* 输入一行字符,统计出其中数字字符的个数. */
#include <iostream>
using namespace std;

int main(){
    string str;
    getline(cin, str);
    int count = 0;
    for (int i=0; i<str.size(); i++){
        if (str[i] >= '0' and str[i] <='9'){
            count++;
        }
    }
    cout << count;
}