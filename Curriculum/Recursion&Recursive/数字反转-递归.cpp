#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

// 返回值 & 函数的参数
string convert(string str){
    if (str.size() <= 0) return "";
    return str[str.size()-1] + convert(str.substr(0, str.size()-1));
}

int main(){
    string str;
    cin >> str;
    cout << convert(str) << endl;
    return 0;
}
