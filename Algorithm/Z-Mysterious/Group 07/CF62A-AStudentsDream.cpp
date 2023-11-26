#include <iostream>
using namespace std;

int main(){
    int al, ar, bl, br;
    cin >> al >> ar >> bl >> br;
    if ((al * 2 + 3 > br && br >= al - 1)||(ar * 2 + 3 > bl && bl >= ar - 1)){
        cout << "YES" << endl;
    } else cout << "NO" << endl;
    return 0;
}