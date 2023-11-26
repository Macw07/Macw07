#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int mini = 0x7f7f7f;
    for (int i=1; i<=3; i++){
        int m, c, v;
        cin >> m >> c;
        if (n%m == 0){
            v = c * (n/m);
        } else{
            v = c* (n/m + 1);
        }
        if (v < mini){
            mini = v;
        }
    }
    cout << mini << endl;
    return 0;
}