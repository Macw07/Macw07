#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    string s, str1, str2;
    int c=0;
    cin >> str1 >> str2;
    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());
    for (int i=0, j=0; i<str1.size() || j<str2.size() || c!=0; ){
        if(i<str1.size()) c+=str1[i++]-'0';
        if(j<str2.size()) c+=str2[j++]-'0';
        s += c%10+'0';
        c/=10;
    }
    reverse(s.begin(), s.end());
    cout << s;
    return 0;
}