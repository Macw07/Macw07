#include <iostream>
#include <algorithm>
using namespace std;

// KMP算法第一次复习 + 优化（单纯长得好看点罢了）

int prefix[1000005];

void move_prefix_table(string str){
    for (int i=str.size(); i>0; i--){
        prefix[i] = prefix[i-1];
    }
    prefix[0] = -1;
    return ;
}

void create_prefix_table(string str){
    int n = str.size();
    int i = 1, len = 0;
    while(i < n){
        if (str[i] == str[len]) prefix[i++] = ++len;
        else{
            if (len - 1 >= 0) len = prefix[len-1];
            else prefix[i++] = 0, len = 0;
        }
    }
    move_prefix_table(str);
    return ;
}

void KMP(string s1, string s2){
    create_prefix_table(s2);
    int n = s1.size(), m = s2.size();
    int i = 0, j = 0;
    while(i < n){
        if (s1[i] == s2[j]) i++, j++;
        else{
            j = prefix[j];
            if (j == -1) j++, i++;
        }
        if (j == m) cout << (i-j+1) << endl;
    }
    return ;
}

int main(){
    string s1, s2;
    cin >> s1 >> s2;
    KMP(s1, s2);
    for (int i=1; i<=s2.size(); i++) cout << prefix[i] << ' ';
    return 0;
}