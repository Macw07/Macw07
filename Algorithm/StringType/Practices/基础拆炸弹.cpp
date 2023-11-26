/* 抗战时期，很多内容都必须加密，免得被对面截取信息，所以，明明发明了一种加密方法，用加密方法为：
当内容为英文字母时，用26字母中的其后三个字母代替该字母，如果是超过z,就循环到a。
若为其它字符时不变。现在请帮明明用程序计算加密后的结果。 */
#include <iostream>
using namespace std;

int main()
{
    string str;
    cin >> str;
    char res;
    for (int i = 0; i < str.size(); i++)
    {
        char current = str[i];
        if (current >= '0' and current <= '9')
        {
            cout << current;
        }
        else if (current >= 'a' and current <= 'z')
        {
            // cout << int(current) << endl;
            // cout << ((current+3)-97)%26+97 << endl;
            res = (current-97+1)%26+97;
            cout << res;
            res = (current-97+2)%26+97;
            cout << res;
            res = (current-97+3)%26+97;
            cout << res;
        } else if(current >= 'A' and current <= 'Z'){
            res = (current-65+1)%26+65;
            cout << res;
            res = (current-65+2)%26+65;
            cout << res;
            res = (current-65+3)%26+65;
            cout << res;
        }
    }
}
