#include <iostream>
#include <algorithm>
using namespace std;

string recursion(){
    string res = "", str="";
    int k;
    char ch;
    while(cin >> ch){
        if (ch == '['){
            cin >> k;
            str = recursion();
            while(k--){
                res += str;
            }
        } else if (ch == ']') return res;
        else res += ch;
    }
    // return res;
}
int main(){
    cout << recursion();
    return 0;
}