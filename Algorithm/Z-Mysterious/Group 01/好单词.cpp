/* 们把“dos”或“cctv”称为是好单词，因为它的字母是按照 ASCII 码的顺序排列的，
同时规定，一个字母的单词也是好单词；与之相反，“data”就不是一个好单词。 
现请编写一个程序，把一个词库中的好单词挑出来。如果这组都不存在好单词，则输出none。 */



#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int num = 0;
    cin >> num;
    int t = 0;
    while (num--)
    {
        string str;
        cin >> str;
        int length = str.size();
        bool flag = 1;
        for (int i = 0; i < length - 1; i++)
        {
            if (str[i] > str[i + 1])
            {
                flag = 0;
                break;
            }
        }
        if (flag)
        {
            t++;
            cout << str << endl;
        } 
    }
    if (t==0) {
        cout << "none" << endl;
    }
    return 0;
}