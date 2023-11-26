// 给定一个字符，用它构造一个底边长5个字符，高个3字符的等腰字符三角形。
#include <iostream>
using namespace std;

int main(){
    char str;
    cin >> str;
    cout << "  " << str << endl;
    cout << " " << str << str << str << endl;
    cout << str << str << str << str << str << endl;
    return 0;
}