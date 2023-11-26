#include <iostream>
#include <algorithm>
using namespace std;

string s;
int ans = 0x7f7f7f7f;

int rec(int right){
    // 判断自己是否和自己的一半相等
    string temp = "";
    string org = "";
    if (right % 2 == 1) return right;
    if (right-1 == 0) return 1;
    for (int i=0; i<right; i++){
        temp += s[i];
        org += s[i];
    }
    reverse(temp.begin(), temp.end());
    if (temp != org) return temp.size();
    // 否则就截取一半
    return rec(right/2);
}

int main(){
    cin >> s;
    cout << rec(s.size()) << endl;
    return 0;
}