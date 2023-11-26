/* 输入n（n<15），输出n为边长的等边三角形 */

#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    for (int i=1; i<=n; i++){
        for (int j=n-i; j>0; j--){
            cout << " ";
        }
        for (int j=1; j<=i; j++){
            cout << "* ";
        }
        cout << endl;
    }
}