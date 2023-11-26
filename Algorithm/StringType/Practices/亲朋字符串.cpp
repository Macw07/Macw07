/*  亲朋字符串定义如下：给定字符串s的第一个字符的ASCII值加第二个字符的ASCII值，
得到第一个亲朋字符； s的第二个字符加第三个字符得到第二个亲朋字符；依此类推。
注意：亲朋字符串的最后一个字符由s的最后一个字符ASCII值加s的第一个字符的ASCII值。 */
#include <iostream>
using namespace std;

int main(){
    string str;
    cin >> str;
    int j;
    int sum;
    for (int i=0; i<str.size(); i++){
        // sum = int(str[j]) + int(str[j+1]);
        // cout << str[i%str.size()] << str[(i+1)%str.size()-1] << endl;
        int now = str[i%str.size()];
        int now1 = str[(i+1)%str.size()];
        cout << char(now+now1);
    }
}