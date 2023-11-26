// 输入一个小写字母，输出其对应的大写字母。例如输入 q[回车] 时，会输出 Q。
#include <iostream>
using namespace std;

int main(){
    char chr;
    cin >> chr;
    cout << char(chr-32) << endl;
    return 0;
}