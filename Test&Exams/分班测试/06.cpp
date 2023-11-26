#include <iostream>
using namespace std;

string str;
int total, len;
bool f1, f2;

int main(){
    cin >> str;
    len = str.size();
    for (int i=0; i<len; i++){
        if (str[i] == '1') f1 = 1;
        else f2 = 1;
        if (f1 && f2) {
            total += 1;
            f1 = f2 = 0;
        }
    }
    cout << total << endl;
    return 0;
}