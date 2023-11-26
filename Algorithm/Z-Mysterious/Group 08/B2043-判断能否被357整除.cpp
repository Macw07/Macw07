#include <iostream>
using namespace std;

int x, cnt = 0;

int main(){
    cin >> x;
    if (x % 3 == 0){
        cout << 3 << " "; cnt++;
    }
    if (x % 5 == 0){
        cout << 5 << " "; cnt++;
    }
    if (x % 7 == 0){
        cout << 7 << " "; cnt++;
    }
    if (!cnt) cout << 'n' << endl;
    return 0;
}