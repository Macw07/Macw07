/* 宇轩曾经使用过一种很简单的密码。对于明文中的每个字符，
将它用它字母表中后5位对应的字符来代替，这样就得到了密文。比如字符A用F来代替。 */

#include <iostream>
#include <string>
using namespace std;

int main(){
    string str;
    getline(cin, str);
    for (int i=0; i<str.size(); i++){
        if (str[i] >= 'A' and str[i] <= 'Z'){
            cout << char(((str[i]+65-5)%26 +65));
        } else{
            cout << str[i];
        }
    }
}