/*已知三个正整数a，b，c。现有一个大于1的奇数x，将其作为除数分别除a，b，c，得到的余数相同。
请问满足上述条件的x的最小值是多少？数据保证x有解。*/

#include <iostream>
using namespace std;

int main(){
    int a,b,c;
    cin >> a >> b >> c;
    int count = 1;
    while (true){
        count += 2;
        if (a%count == b%count && a%count == c%count){
            break;
        }
    }
    cout << count;
}