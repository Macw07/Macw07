/* 零食中也是有字符串的，烂的零食是大写字母，好的零食是小写字母,数字表示零食中的病毒，
那现在要把烂的零食变成好的零食，把病毒消灭掉（就是变成0）。要怎么变呢 */
#include <iostream>
using namespace std;

int main(){
    string input;
    cin >> input;
    for (int i=0; i < input.size(); i++){
        char current = input[i];
        if (current >= 'A' && current <= 'Z'){
            current += 32;
        } else if(current >= '0' && current <='9'){
            current = '0';
        }
        cout << current;
    }
}