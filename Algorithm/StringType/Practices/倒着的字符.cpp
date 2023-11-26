/* 有一种直角三角形比较的奇怪，它是倒着的，而且呢，
上面挂满了大写字母，所有大写字母都是按照顺序依次排列的，
现在输入一个n（1<=n<20），表示有n行，每行都挂满有顺序的大写字母。 */

#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int number_count = 65;
    for (int i=0; i<=n; i++){
        for (int j=n-i-1; j>=0; j--){
            cout << char(number_count);
            if (number_count + 1 >= 91){
                number_count = (number_count - 65 + 1)%26+65;
            } else{
                number_count += 1;
            }
        }
        cout << endl;
    }
}