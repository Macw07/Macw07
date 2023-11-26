#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

char vow[] = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};

int main(){
    string str;
    while(cin >> str){
        bool flag = true;
        for (int i=0; i<5; i++) {
            if (str[0] == vow[i]) flag = false;
        }
        if (flag) {
            for (int i=1; i<str.size(); i++){
                cout << str[i];
            }
            cout << '-' << str[0] << "ay ";
        }
        else cout << str+"-yay ";
    }
    return 0;
}