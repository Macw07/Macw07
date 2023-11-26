#include <iostream>
#include <string>
using namespace std;

int main(){
    string s1, s2;
    int count=0, location=-1;
    getline(cin, s1);
    getline(cin, s2);
    int l1 = s1.size(), l2 = s2.size();
    // 转换成小写
    for (int i=0; i<l1; i++) if (s1[i] >= 'a' && s1[i] <= 'z') s1[i] -= 32;
    for (int i=0; i<l2; i++) if (s2[i] >= 'a' && s2[i] <= 'z') s2[i] -= 32;
    // 开始匹配
    for (int i=0; i<l2; i++){
        if (s2[i] == s1[0] && i+l1 <= l2){
            if (i != 0){
                if (i >= 1 && s2[i-1] != ' ') continue;
            }
            if (i+l1 != l2){
                if (s2[i+l1] != ' ') continue;
            }
            string s;
            for (int j=i; j<i+l1; j++){
                s += s2[j];
            }
            // cout << s << " ";
            if (s == s1){
                count++;
                if (location < 0) location = i;
            }    
        }
    }
    if (location >= 0) {
        cout << count << " " << location;
    } else{
        cout << -1;
    }
    return 0;
}