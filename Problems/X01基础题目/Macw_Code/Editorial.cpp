#include <iostream>
#include <algorithm>
using namespace std;

int n, len;
string str;

int main(){    
    getline(cin, str); cin >> n;
    len = str.size();

    // 字符串翻转
    string tmp = "", mode = "";
    for (int i=0; i<=len; i++){
        if (i == len){
            reverse(tmp.begin(), tmp.end());
            mode += tmp;
            continue;
        }
        if (str[i] == ' '){
            reverse(tmp.begin(), tmp.end());
            mode += tmp;
            mode += str[i];
            tmp = "";
        } else{
            tmp += str[i];
        }
    }
    // cout << mode << endl;
    // 字符串加密
    for (int i=0; i<len; i++){
        if (mode[i] >= 'A' && mode[i] <= 'Z'){
            int k = (mode[i] + n - 65)%26 + 65;
            mode[i] = k;
        } else if (mode[i] >= 'a' && mode[i] <= 'z'){
            int k = (mode[i] + n - 97)%26 + 97;
            mode[i] = k;
        }
    }
    cout << mode << endl;
    return 0;
}