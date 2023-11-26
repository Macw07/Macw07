/* 给定若干个四位数，求出其中满足以下条件的数的个数：
个位数上的数字减去千位数上的数字，再减去百位数上的数字，再减去十位数上的数字的结果大于零。 */
#include <iostream>
using namespace std;

int main(){
    int times;
    cin >> times;
    int numArr[times];
    for (int i=0; i<times; i++){
        int number;
        cin >> number;
        numArr[times] = number;
    }
    int count = 0;
    for (int i=0; i<sizeof(numArr)/sizeof(numArr[0]); i++){
        int fitst = numArr[i] / 1 % 10;
        int second = numArr[i] / 10 % 10;
        int third = numArr[i] / 100 % 10;
        int fourth = numArr[i] / 1000 % 10;

        if ((fitst - fourth - third - second) >= 0){
            count += 1;
        }
    }
    cout << count << endl;
}