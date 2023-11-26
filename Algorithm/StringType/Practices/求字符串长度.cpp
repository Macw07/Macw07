// 求字符串长度

#include <iostream>
using namespace std;

void len(string str);

int main(){
    string str = "HelloWorld!";
    len(str);
}

void len(string str){
    int count=0;
    while (str[count]){
        count++;
    }
    cout << count << endl;
}