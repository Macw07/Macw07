#include <iostream>
#include <string>
using namespace std;

int main(){
    string s;
    getline(cin, s);
    int len = s.size(), count = 0;
    for (int i=0; i<len; i++){
        if (s[i] != ' ') count++;
    }
    cout << count;
    return 0;
}