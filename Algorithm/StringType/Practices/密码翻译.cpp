/* 在情报传递过程中，为了防止情报被截获，往往需要对情报用一定的方式加密，
简单的加密算法虽然不足以完全避免情报被破译，但仍然能防止情报被轻易的识别。
我们给出一种最简的的加密方法，对给定的一个字符串，
把其中从 a-y，A-Y 的字母用其后继字母替代，把 z 和 Z 用 a 和 A 替代，
其他非字母字符不变，则可得到一个简单的加密字符串。 */
#include <iostream>
#include <string>
using namespace std;

int main(){
    string str;
    getline(cin, str);
    for (int i=0; i<str.size(); i++){
        if (str[i] >= 'a' and str[i] <= 'z'){
            str[i] = (str[i]+1-97)%26+97;
        }
        else if (str[i] >= 'A' and str[i] <= 'Z'){
            str[i] = (str[i]+1-65)%26+65;
        }
    }
    cout << str;
}