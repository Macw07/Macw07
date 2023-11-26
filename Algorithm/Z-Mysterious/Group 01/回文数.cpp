/* 输入一个数n，这个数倒过来和原数一样，我们称其为回文数，比如121，倒过来还是121，就是回文数 */

#include <iostream>
using namespace std;

int main(){
    int num;
    cin >> num;
    int ans = 0;
    int m = num;
    while (m>0){
        ans = ans * 10 + m % 10;
        m /= 10;
    }
    if (ans == num){
        cout << "YES";
    } else {
        cout << "NO";
    }
}