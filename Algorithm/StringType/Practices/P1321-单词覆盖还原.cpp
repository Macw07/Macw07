#include <iostream>
#include <algorithm>
using namespace std;

string s;
int a, b;

int main(){
    cin >> s;
    for (int i=0; i<s.size(); i++){
        if (s[i] == 'b' || s[i+1] == 'o' || s[i+2] == 'y') a++;
        if (s[i] == 'g' || s[i+1] == 'i' || s[i+2] == 'r' || s[i+3] == 'l') b++;
    }
    cout << a << endl << b;
    return 0;
}