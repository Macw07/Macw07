/* 如果一个数从左往右读和从右往左读都是一样，那么这个数就叫做“回文数”。
例如，12321 就是一个回文数，而 77778 就不是。当然，回文数的首和尾都应是非零的，因此 0220 就不是回文数。
事实上，有一些数（如 33 ），在十进制时是回文数，在二进制时（ 100001 ）时也是回文数，
我们姑且将这样的数叫做双重回文数，请你找出两个整数之间的所有双重回文数，如果没有，输出-1 */

#include <iostream>
using namespace std;

bool binary(int number){
    int arr[100] = {};
    int r_arr[100] = {};
    int count = 0;
    int res = 0;
    while (number){
        arr[count] = number % 2;
        number /= 2;
        count++;
    }
    for (int i=0; i<count; i++){
        r_arr[count-i-1] = arr[i];
    }
    for (int i=0; i<count; i++){
        if (arr[i] != r_arr[i]){
            return false;
        }
    }
    return true;
}

bool reverse(int number){
    int result=0;
    int n = number;
    while (n){
        result = result*10 + n%10;
        n /= 10;
    }
    if (result==number){
        return true;
    }
    return false;
}

int main(){
    int begin, end;
    cin >> begin >> end;
    bool flag=0;
    for (int i=begin; i<end; i++){
        bool a = binary(i);
        bool b = reverse(i);
        if (a && b){
            cout << i << endl;
            flag = 1;
        }
    }
    if (!flag){
        cout << -1;
    }
}

