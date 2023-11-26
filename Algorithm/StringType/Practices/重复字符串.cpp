/* 求字符串 str中，检查其是否包含连续重复的字母，包含返回 true，否则返回 false */

#include <iostream>
using namespace std;

int main()
{
    string str;
    cin >> str;
    bool flag = 0;
    for (int i = 0; i < str.size() - 1; i++)
    {
        if (str[i] == str[i + 1])
        {
            flag = 1;
            cout << "true" << endl;
            break;
        }
    }
    if (!flag)
        {
            cout << "false" << endl;
        }
}