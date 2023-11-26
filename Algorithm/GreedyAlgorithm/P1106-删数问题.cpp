#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

string str;
int k;

int convert(string s){
    int sum = 0;
    for (int i=0; i<s.size(); i++) sum = sum*10 + s[i]-'0';
    return sum;
}
int main(){
    cin >> str >> k;
    for (int i=0; i<k; i++){
        string temp;
        bool flag = true;
        for (int j=0; j<str.size(); j++){
            if (str[j+1] < str[j] && flag){
                flag = false;
                continue;
            }
            temp += str[j];
        }
        str = temp;
    }
    cout << convert(str) << endl;
    return 0;
}