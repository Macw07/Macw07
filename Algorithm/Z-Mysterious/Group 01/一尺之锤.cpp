/* 《庄子》中说到，“一尺之棰，日取其半，万世不竭”。第一天有一根长度为 a (a≤109) 的木棍，
从第二天开始，每天都要将这根木棍锯掉一半（每次除 2，向下取整）。第几天的时候木棍会变为 0？*/
#include <iostream>
using namespace std;

int main(){
    int len;
    cin >> len;
    int count = 0;
    while (len){
        count += 1;
        len = int(len/2);
    }
    cout << count;
}