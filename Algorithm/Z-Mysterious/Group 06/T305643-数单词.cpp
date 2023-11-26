#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int main(){
    int cnt = 0;
    string s;
    getline(cin, s);
    for (int i=0; i<s.size(); i++){
        if (s[i] >= 'a' && s[i] <= 'z') s[i] -= 32;
    }
    for (int i=0; i<s.size()-7; i++){
        string temp;
        for (int j=i; j<i+7; j++){
            temp += s[j];
        }
        if (temp == "LANQIAO") cnt++;
    }
    cout << cnt << endl;
    return 0;
}