#include <iostream>
#include <string>
using namespace std;

string convert(string s){
    int l = s.length();
    if (s[0] >= 'a' && s[0] <= 'z') s[0] -= 32;
    for (int i=1; i<l; i++){
        if (s[i] >= 'A' && s[i] <= 'Z') s[i] += 32;
    }
    return s;
}
int main(){
    int n;
    cin >> n;
    for (int i=0; i<n; i++){
        string s;
        cin >> s;
        cout << convert(s) << endl;
    }
    return 0;
}