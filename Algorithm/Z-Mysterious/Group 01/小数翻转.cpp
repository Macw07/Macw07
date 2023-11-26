// 输入一个不小于100且小于1000，同时包括小数点后一位的一个浮点数

#include <iostream>
using namespace std;

int main(){
    string n;
    cin >> n;
    for (int i=n.size(); i>=0; i--){
        cout << n[i-1];
    }
    return 0;
}