/* 一段字符中，想输出的时候大写变小写，小写变大写，然后数字不变。 */
#include <iostream>
using namespace std;

int main(){
    string str;
    cin >> str;
    for (int i=0; i<str.size(); i++){
        if (str[i] >= 'a' && str[i] <= 'z'){
            str[i] = str[i]-32;
        } else if (str[i] >= 'A' && str[i] <= 'Z'){
            str[i] = str[i]+32;
        }
    }
    cout << str << endl;
}