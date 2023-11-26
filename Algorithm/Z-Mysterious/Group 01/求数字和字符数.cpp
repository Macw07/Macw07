/* 输入一段字符，他统计这段字符中有多少个字符，有多少个数字 */
#include <iostream>
using namespace std;

int main(){
    string str;
    cin >> str;
    int count_str=0;
    int count_num=0;
    for (int i=0; i < str.size(); i++){
        if (str[i] >= '0' && str[i] <= '9'){
            count_num += 1;
        } else {
            count_str += 1;
        }
    }
    cout << "Letters=" << count_str << endl;
    cout << "Digits=" << count_num << endl;
}