#include <iostream>
#include <cstring>
using namespace std;

string m = "VWXYZABCDEFGHIJKLMNOPQRSTU";

int main(){
    string str;
    getline(cin, str);
    int len = str.size();
    for (int i=0; i<len; i++){
        if (str[i] >= 'A' && str[i] <= 'Z'){
            cout << m[str[i]-65];
        } else {
            cout << str[i];
        }
    }
    return 0;
}