// 给定一个只包含小写字母的字符串，请你找到第一个仅出现一次的字符。如果没有，输出no
#include <iostream>
using namespace std;

int arr[100] = {};
int times[100] = {};

int pointer = 0;
bool add_in(char c, int cc);

int main(){
    string str;
    cin >> str;
    for (int i=0; i<str.size(); i++){
        add_in(str[i], i);
    }
    for (int i=0; i<pointer; i++){
        if (times[i] == 0){
            cout << char(arr[i]) << endl;;
            return 0;
        }
    }
    cout << "no" << endl;
    return 0;
}

bool add_in(char c, int cc){
    for (int i=0; i<cc; i++){
        if (arr[i] == c){
            times[i] += 1;
            return true;
        }
    }
    arr[pointer] = c;
    pointer++;
    return true;
}