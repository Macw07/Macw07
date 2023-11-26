#include <iostream>
#include <cstring>
using namespace std;

string s;

string rec(int left, int right){
    // 若字符串全是0
    bool flag = 1;
    for (int i=left; i<right; i++){
        if (s[i] == '1'){
            flag = 0;
            break;
        }
    }
    if (flag) return "A";
    // 若字符串全是1
    flag = 1;
    for (int i=left; i<right; i++){
        if (s[i] == '0'){
            flag = 0;
            break;
        }
    }
    if (flag) return "B";
    // 否则继续递归
    // cout << left << " " << right << endl;
    int mid = (left+right)/2;
    return "C" + rec(left, mid) + rec(mid, right);
}

int main(){
    cin >> s;
    cout << rec(0, s.size());
    return 0;
}